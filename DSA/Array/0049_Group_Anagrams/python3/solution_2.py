# 0049. Group Anagrams
# Difficulty : Medium
# Tags       : array, hash-table, string, sorting
# Solved on  : 2026-05-18
# Attempt    : #2
# LeetCode   : https://leetcode.com/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for _,x in enumerate(strs):
            count = [0] * 26
            for _,ch in enumerate(x):
                asc = ord(ch) - ord('a')
                count[asc]+=1
            key = ",".join(map(str,count))
            if key not in mp:
                mp[key] = []
            mp[key].append(x)
        return [val for _,val in enumerate(mp.values())]
        