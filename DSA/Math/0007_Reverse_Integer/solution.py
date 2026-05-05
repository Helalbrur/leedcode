# 0007. Reverse Integer
# Difficulty : Medium
# Tags       : math
# Solved on  : 2026-04-20
# LeetCode   : https://leetcode.com/problems/reverse-integer/

class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        rev = int(str(abs(x))[::-1])
        if rev > 2**31 -1:
            return 0
        else:
            return sign * rev