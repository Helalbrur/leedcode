# 3110. Score of a String
# Difficulty : Easy
# Tags       : string
# Solved on  : 2025-10-20
# LeetCode   : https://leetcode.com/problems/score-of-a-string/

class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0
        for i in range(0,len(s)-1):
            score = score + abs(ord(s[i])-ord(s[i+1]))
        return score
        