# 0062. Unique Paths
# Difficulty : Medium
# Tags       : math, dynamic-programming, combinatorics
# Solved on  : 2026-04-30
# LeetCode   : https://leetcode.com/problems/unique-paths/

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return math.comb((m+n-2),(m-1))
        