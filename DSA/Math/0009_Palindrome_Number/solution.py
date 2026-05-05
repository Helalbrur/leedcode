# 0009. Palindrome Number
# Difficulty : Easy
# Tags       : math
# Solved on  : 2026-04-21
# LeetCode   : https://leetcode.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x: int) -> bool:
        return x >=0 and str(x) == str(x)[::-1]