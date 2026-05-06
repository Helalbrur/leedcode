import re
import requests
import os
import json
import time
from dotenv import load_dotenv
from datetime import datetime, timezone
from git import Repo

# ================= CONFIG =================
load_dotenv()

LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")
CSRF_TOKEN       = os.getenv("CSRF_TOKEN")
USERNAME         = os.getenv("USERNAME", "Helaluddin")
REPO_PATH        = os.getenv("REPO_PATH")

HEADERS = {
    "cookie":           f"LEETCODE_SESSION={LEETCODE_SESSION}; csrftoken={CSRF_TOKEN}",
    "x-csrftoken":      CSRF_TOKEN,
    "x-requested-with": "XMLHttpRequest",
    "content-type":     "application/json",
    "referer":          "https://leetcode.com",
    "user-agent":       "Mozilla/5.0",
    "origin":           "https://leetcode.com",
    "accept":           "application/json",
}

GRAPHQL_URL  = "https://leetcode.com/graphql"
TRACKER_FILE = os.path.join(REPO_PATH, ".sync_tracker.json")

# ============== CATEGORY MAP ==============
CATEGORY_MAP = {
    "array":                "Array",
    "string":               "String",
    "hash-table":           "HashTable",
    "dynamic-programming":  "DynamicProgramming",
    "graph":                "Graph",
    "tree":                 "Tree",
    "binary-tree":          "Tree",
    "math":                 "Math",
    "greedy":               "Greedy",
    "binary-search":        "BinarySearch",
    "linked-list":          "LinkedList",
    "stack":                "Stack",
    "queue":                "Queue",
    "heap-priority-queue":  "Heap",
    "sorting":              "Sorting",
    "two-pointers":         "TwoPointers",
    "sliding-window":       "SlidingWindow",
    "backtracking":         "Backtracking",
    "bit-manipulation":     "BitManipulation",
    "depth-first-search":   "Graph",
    "breadth-first-search": "Graph",
    "recursion":            "Recursion",
    "trie":                 "Trie",
    "matrix":               "Matrix",
    "number-theory":        "Math",
    "simulation":           "Simulation",
    "counting":             "Math",
    "prefix-sum":           "Array",
}

# Maps LeetCode lang string → Programming Languages subfolder name
LANG_FOLDER_MAP = {
    "python3":    "Python",
    "python":     "Python",
    "php":        "PHP",
    "javascript": "JavaScript",
    "typescript": "JavaScript",   # grouped under JavaScript
    "cpp":        "CPP",
    "c":          "CPP",          # grouped under CPP
    "java":       "Java",
    "csharp":     "CSharp",
    "go":         "Go",
    "ruby":       "Ruby",
    "swift":      "Swift",
    "kotlin":     "Kotlin",
    "rust":       "Rust",
    "scala":      "Scala",
}

LANG_EXT = {
    "cpp": "cpp", "python": "py", "python3": "py",
    "javascript": "js", "typescript": "ts", "java": "java",
    "c": "c", "csharp": "cs", "go": "go", "ruby": "rb",
    "swift": "swift", "kotlin": "kt", "rust": "rs",
    "php": "php", "scala": "scala",
}

LANG_COMMENT = {
    "py": "#",  "js": "//", "ts": "//", "cpp": "//",
    "c":  "//", "java": "//", "cs": "//", "go": "//",
    "rb": "#",  "swift": "//", "kt": "//", "rs": "//",
    "php": "//", "scala": "//",
}

# ============== TRACKER ==============
def load_tracker() -> dict:
    if os.path.exists(TRACKER_FILE):
        with open(TRACKER_FILE, "r") as f:
            return json.load(f)
    return {"synced_ids": [], "problems": {}, "counts": {}}

def save_tracker(tracker: dict):
    with open(TRACKER_FILE, "w") as f:
        json.dump(tracker, f, indent=2)

# ============== FETCH ALL SUBMISSIONS (paginated) ==============
def fetch_submissions() -> list:
    """
    Returns EVERY Accepted submission (all pages).
    recentAcSubmissionList is hard-capped at 20 — do NOT use it.
    """
    query = """
    query submissions($offset: Int!, $limit: Int!, $lastKey: String) {
      submissionList(offset: $offset, limit: $limit, lastKey: $lastKey) {
        lastKey
        hasNext
        submissions {
          id
          title
          titleSlug
          timestamp
          statusDisplay
          lang
        }
      }
    }
    """
    all_accepted = []
    offset    = 0
    page_size = 20
    last_key  = None
    page      = 1

    while True:
        print(f"  📄 Fetching page {page} (offset {offset})…")
        resp = requests.post(
            GRAPHQL_URL,
            headers=HEADERS,
            json={"query": query, "variables": {"offset": offset, "limit": page_size, "lastKey": last_key}},
            timeout=15,
        )
        resp.raise_for_status()
        payload = resp.json()

        if "errors" in payload:
            print(f"  ⚠ GraphQL error on page {page}: {payload['errors']}")
            break

        data             = payload["data"]["submissionList"]
        accepted_on_page = [s for s in data["submissions"] if s["statusDisplay"] == "Accepted"]
        all_accepted.extend(accepted_on_page)

        print(f"     → {len(data['submissions'])} total, {len(accepted_on_page)} accepted this page")

        if not data["hasNext"]:
            break

        last_key  = data.get("lastKey")
        offset   += page_size
        page     += 1
        time.sleep(0.4)

    print(f"\n  Total accepted submissions fetched: {len(all_accepted)}")
    return all_accepted

# ============== FETCH CODE ==============
def fetch_code(submission_id: str) -> str | None:
    query = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        lang { name verboseName }
      }
    }
    """
    try:
        resp = requests.post(
            GRAPHQL_URL,
            headers=HEADERS,
            json={"query": query, "variables": {"submissionId": int(submission_id)}},
            timeout=15,
        )
        if resp.status_code == 200:
            details = (resp.json().get("data") or {}).get("submissionDetails")
            if details and details.get("code"):
                return details["code"]
    except Exception as e:
        print(f"    ⚠ GraphQL failed: {e}")

    # HTML fallback
    try:
        url  = f"https://leetcode.com/submissions/detail/{submission_id}/"
        page = requests.get(url, headers=HEADERS, timeout=15)
        if page.status_code == 200:
            m = re.search(r"submissionCode\s*:\s*'(.*?)'(?:,|\s*\n)", page.text, re.DOTALL)
            if m:
                return m.group(1).encode("raw_unicode_escape").decode("unicode_escape")
            m2 = re.search(r'"code"\s*:\s*"((?:[^"\\]|\\.)*)"', page.text)
            if m2:
                return m2.group(1).encode("raw_unicode_escape").decode("unicode_escape")
    except Exception as e:
        print(f"    ⚠ HTML scrape failed: {e}")

    print(f"    ✗ Could not retrieve code for submission {submission_id}")
    return None

# ============== FETCH PROBLEM DETAIL ==============
def fetch_problem_detail(title_slug: str) -> dict:
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId difficulty
        topicTags { name slug }
      }
    }
    """
    resp = requests.post(
        GRAPHQL_URL,
        headers=HEADERS,
        json={"query": query, "variables": {"titleSlug": title_slug}},
        timeout=15,
    )
    resp.raise_for_status()
    q = resp.json()["data"]["question"]
    return {
        "number":     q.get("questionFrontendId", "0"),
        "difficulty": q.get("difficulty", "Unknown"),
        "tags":       [t["slug"] for t in q.get("topicTags", [])],
    }

# ============== BUILD FILE CONTENT ==============
def build_file(sub: dict, code: str, detail: dict, attempt_num: int, ext: str) -> str:
    comment = LANG_COMMENT.get(ext, "#")
    number  = detail["number"].zfill(4)
    date    = datetime.fromtimestamp(int(sub["timestamp"]), tz=timezone.utc).strftime("%Y-%m-%d")
    header  = (
        f"{comment} {number}. {sub['title']}\n"
        f"{comment} Difficulty : {detail['difficulty']}\n"
        f"{comment} Tags       : {', '.join(detail['tags'])}\n"
        f"{comment} Solved on  : {date}\n"
        f"{comment} Attempt    : #{attempt_num}\n"
        f"{comment} LeetCode   : https://leetcode.com/problems/{sub['titleSlug']}/\n\n"
    )
    return header + code

# ============== SAVE SOLUTION ==============
def save_solution(sub: dict, code: str, detail: dict, attempt_num: int):
    """
    Saves each solution to TWO locations:

    1. DSA (by topic category):
       DSA/<Category>/<0001_Title>/<lang>/solution.py
       DSA/<Category>/<0001_Title>/<lang>/solution_2.py  ← for 2nd attempt

    2. Programming Languages (by language):
       Programming Languages/Python/<0001_Title>/solution.py
       Programming Languages/Python/<0001_Title>/solution_2.py
    """
    # ── shared metadata ──────────────────────────────────────────────
    category = "Misc"
    for tag in detail["tags"]:
        if tag in CATEGORY_MAP:
            category = CATEGORY_MAP[tag]
            break

    number   = detail["number"].zfill(4)
    title    = sub["title"].replace(" ", "_")
    lang     = sub["lang"].lower()
    ext      = LANG_EXT.get(lang, "txt")
    filename = "solution" if attempt_num == 1 else f"solution_{attempt_num}"
    content  = build_file(sub, code, detail, attempt_num, ext)
    date_str = datetime.fromtimestamp(int(sub["timestamp"]), tz=timezone.utc).strftime("%Y-%m-%d")

    # ── 1. DSA/<Category>/<number_Title>/<lang>/ ─────────────────────
    dsa_folder = os.path.join(REPO_PATH, "DSA", category, f"{number}_{title}", lang)
    os.makedirs(dsa_folder, exist_ok=True)
    with open(os.path.join(dsa_folder, f"{filename}.{ext}"), "w", encoding="utf-8") as f:
        f.write(content)

    # update the problem-level README (sits above the lang subfolder)
    write_problem_readme(os.path.dirname(dsa_folder), sub, detail, date_str)
    print(f"    ✅ DSA    → DSA/{category}/{number}_{title}/{lang}/{filename}.{ext}")

    # ── 2. Programming Languages/<LangFolder>/<number_Title>/ ────────
    lang_folder_name = LANG_FOLDER_MAP.get(lang, lang.capitalize())
    pl_folder = os.path.join(REPO_PATH, "Programming Languages", lang_folder_name, f"{number}_{title}")
    os.makedirs(pl_folder, exist_ok=True)
    with open(os.path.join(pl_folder, f"{filename}.{ext}"), "w", encoding="utf-8") as f:
        f.write(content)

    # per-problem README inside the language folder too
    write_pl_readme(pl_folder, sub, detail, date_str, lang_folder_name)
    print(f"    ✅ Lang   → Programming Languages/{lang_folder_name}/{number}_{title}/{filename}.{ext}")

# ============== PROBLEM README (DSA) ==============
def write_problem_readme(folder: str, sub: dict, detail: dict, date: str):
    """Problem folder README — shows all language subfolders and their attempts."""
    lang_rows = ""
    if os.path.isdir(folder):
        for lang_dir in sorted(os.listdir(folder)):
            lang_path = os.path.join(folder, lang_dir)
            if not os.path.isdir(lang_path):
                continue
            for sol in sorted(f for f in os.listdir(lang_path) if f.startswith("solution")):
                lang_rows += f"| `{lang_dir}` | [{sol}](./{lang_dir}/{sol}) |\n"

    content = f"""# {detail['number']}. {sub['title']}

| Field       | Value |
|-------------|-------|
| Difficulty  | {detail['difficulty']} |
| Tags        | {', '.join(f'`{t}`' for t in detail['tags'])} |
| Last solved | {date} |
| Link        | [LeetCode](https://leetcode.com/problems/{sub['titleSlug']}/) |

## Solutions

| Language | File |
|----------|------|
{lang_rows}"""
    with open(os.path.join(folder, "README.md"), "w", encoding="utf-8") as f:
        f.write(content)

# ============== PROBLEM README (Programming Languages) ==============
def write_pl_readme(folder: str, sub: dict, detail: dict, date: str, lang_name: str):
    """README inside the Programming Languages problem folder."""
    sol_rows = ""
    for sol in sorted(f for f in os.listdir(folder) if f.startswith("solution")):
        sol_rows += f"| [{sol}](./{sol}) |\n"

    content = f"""# {detail['number']}. {sub['title']}

| Field       | Value |
|-------------|-------|
| Difficulty  | {detail['difficulty']} |
| Language    | {lang_name} |
| Tags        | {', '.join(f'`{t}`' for t in detail['tags'])} |
| Last solved | {date} |
| Link        | [LeetCode](https://leetcode.com/problems/{sub['titleSlug']}/) |

## Attempts

| File |
|------|
{sol_rows}"""
    with open(os.path.join(folder, "README.md"), "w", encoding="utf-8") as f:
        f.write(content)

# ============== GENERATE LANGUAGE INDEX READMEs ==============
def generate_language_index_readmes():
    """
    Writes a README.md inside each Programming Languages/<Lang>/ folder
    listing every problem solved in that language.
    """
    pl_root = os.path.join(REPO_PATH, "Programming Languages")
    if not os.path.isdir(pl_root):
        return

    for lang_name in sorted(os.listdir(pl_root)):
        lang_path = os.path.join(pl_root, lang_name)
        if not os.path.isdir(lang_path):
            continue

        problems = sorted(
            d for d in os.listdir(lang_path)
            if os.path.isdir(os.path.join(lang_path, d))
        )
        rows = "\n".join(
            f"| [{p}](./{p}/) |"
            for p in problems
        )
        content = f"""# {lang_name} Solutions

{len(problems)} problem(s) solved in {lang_name}.

| Problem |
|---------|
{rows}
"""
        with open(os.path.join(lang_path, "README.md"), "w", encoding="utf-8") as f:
            f.write(content)

# ============== GENERATE MAIN README ==============
def generate_main_readme(tracker: dict):
    problems         = tracker.get("problems", {})
    total            = len(problems)
    difficulty_count = {"Easy": 0, "Medium": 0, "Hard": 0}
    category_count   = {}
    lang_count       = {}
    rows             = []

    for slug, p in sorted(problems.items(), key=lambda x: int(x[1].get("number", 0))):
        diff = p.get("difficulty", "Unknown")
        difficulty_count[diff] = difficulty_count.get(diff, 0) + 1
        cat  = p.get("category", "Misc")
        category_count[cat]    = category_count.get(cat, 0) + 1

        langs = p.get("langs", [p.get("lang", "")])
        for l in langs:
            folder_name = LANG_FOLDER_MAP.get(l.lower(), l)
            lang_count[folder_name] = lang_count.get(folder_name, 0) + 1

        diff_badge = {"Easy": "🟢 Easy", "Medium": "🟡 Medium", "Hard": "🔴 Hard"}.get(diff, diff)
        rows.append(
            f"| {p.get('number','').zfill(4)} "
            f"| [{p.get('title', slug)}](https://leetcode.com/problems/{slug}/) "
            f"| {diff_badge} "
            f"| {cat} "
            f"| {', '.join(f'`{l}`' for l in langs)} "
            f"| {p.get('date', '')} |"
        )

    cat_rows = "\n".join(
        f"| {cat} | {cnt} |"
        for cat, cnt in sorted(category_count.items(), key=lambda x: -x[1])
    )

    lang_rows = "\n".join(
        f"| [{lang}](./Programming%20Languages/{lang}/) | {cnt} |"
        for lang, cnt in sorted(lang_count.items(), key=lambda x: -x[1])
    )

    readme = f"""# 🧠 LeetCode Solutions — @{USERNAME}

Auto-synced with Python · Last updated: {datetime.now(tz=timezone.utc).strftime("%Y-%m-%d %H:%M UTC")}

## 📊 Stats

| Total Problems | 🟢 Easy | 🟡 Medium | 🔴 Hard |
|----------------|---------|-----------|---------|
| {total} | {difficulty_count.get('Easy', 0)} | {difficulty_count.get('Medium', 0)} | {difficulty_count.get('Hard', 0)} |

## 🗂️ Browse by Topic

> [`DSA/`](./DSA/) — solutions organised by data structure / algorithm category

| Category | Problems |
|----------|----------|
{cat_rows}

## 💻 Browse by Language

> [`Programming Languages/`](./Programming%20Languages/) — same solutions organised by language

| Language | Solutions |
|----------|-----------|
{lang_rows}

## 📋 All Solutions

| # | Title | Difficulty | Category | Languages | Last Solved |
|---|-------|------------|----------|-----------|-------------|
{chr(10).join(rows)}
"""
    with open(os.path.join(REPO_PATH, "README.md"), "w", encoding="utf-8") as f:
        f.write(readme)
    print("  📄 README.md updated")

# ============== GIT PUSH ==============
def push_to_github():
    repo = Repo(REPO_PATH)
    repo.git.add(A=True)
    if not repo.is_dirty(index=True, working_tree=True, untracked_files=True):
        print("Nothing new to commit.")
        return
    repo.index.commit(
        f"🤖 Auto-sync LeetCode solutions [{datetime.now(tz=timezone.utc).strftime('%Y-%m-%d %H:%M')} UTC]"
    )
    repo.remote(name="origin").push()
    print("🚀 Pushed to GitHub!")

# ============== MAIN ==============
def run():
    if not LEETCODE_SESSION or not CSRF_TOKEN:
        raise EnvironmentError("Set LEETCODE_SESSION and CSRF_TOKEN in your .env file.")
    if not REPO_PATH:
        raise EnvironmentError("Set REPO_PATH in your .env file.")

    tracker    = load_tracker()
    synced_ids = set(tracker["synced_ids"])
    counts     = tracker.setdefault("counts", {})
    new_count  = 0

    print(f"🔍 Fetching ALL submissions for @{USERNAME}…\n")
    submissions = fetch_submissions()
    print()

    # Process oldest-first → attempt numbers are assigned chronologically
    for sub in reversed(submissions):
        sub_id = str(sub["id"])
        if sub_id in synced_ids:
            continue  # already saved, silent skip

        print(f"  ⬇ Processing: {sub['title']} ({sub['lang']})  [id={sub_id}]")

        code = fetch_code(sub_id)
        if not code:
            continue

        detail = fetch_problem_detail(sub["titleSlug"])

        count_key         = f"{sub['titleSlug']}::{sub['lang']}"
        attempt_num       = counts.get(count_key, 0) + 1
        counts[count_key] = attempt_num

        save_solution(sub, code, detail, attempt_num)

        # ── update tracker ──
        category = "Misc"
        for tag in detail["tags"]:
            if tag in CATEGORY_MAP:
                category = CATEGORY_MAP[tag]
                break

        date_str = datetime.fromtimestamp(int(sub["timestamp"]), tz=timezone.utc).strftime("%Y-%m-%d")
        existing = tracker["problems"].get(sub["titleSlug"], {})
        langs    = existing.get("langs", [])
        if sub["lang"] not in langs:
            langs.append(sub["lang"])

        tracker["problems"][sub["titleSlug"]] = {
            "number":     detail["number"],
            "title":      sub["title"],
            "difficulty": detail["difficulty"],
            "category":   category,
            "langs":      langs,
            "lang":       sub["lang"],
            "date":       date_str,
        }
        synced_ids.add(sub_id)
        tracker["synced_ids"].append(sub_id)
        new_count += 1
        time.sleep(0.5)

    if new_count:
        generate_language_index_readmes()
        generate_main_readme(tracker)
        save_tracker(tracker)
        push_to_github()
        print(f"\n✅ Done! {new_count} new submission(s) synced.")
    else:
        print("\n✅ Everything already up to date.")

if __name__ == "__main__":
    run()
