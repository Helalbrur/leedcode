# 2942. Find Words Containing Character
# Difficulty : Easy
# Tags       : array, string
# Solved on  : 2025-10-20
# Attempt    : #2
# LeetCode   : https://leetcode.com/problems/find-words-containing-character/

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        res = []
        for i,word in enumerate(words):
            for c in words[i]:
                if c == x:
                    res.append(i)
                    break
        return res