# 0120. Triangle
# Difficulty : Medium
# Tags       : array, dynamic-programming
# Solved on  : 2026-05-05
# LeetCode   : https://leetcode.com/problems/triangle/

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        mx = 2 << 31 -1
        m = len(triangle)
        @lru_cache(None)
        def minT(i,j):
            n = len(triangle[i])
            if i >= m or j >= n:
                return mx
            if i == m -1:
               return triangle[i][j]
            return min(minT(i+1,j),minT(i+1,j+1)) + triangle[i][j]
        return minT(0,0)
            