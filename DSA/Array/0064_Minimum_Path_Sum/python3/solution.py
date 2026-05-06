# 0064. Minimum Path Sum
# Difficulty : Medium
# Tags       : array, dynamic-programming, matrix
# Solved on  : 2026-05-04
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/minimum-path-sum/

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [[10000000 for _ in range(201)] for _ in range(201)]
        m , n = len(grid) , len(grid[0])
        def minPath(i : int,j : int):
            if i >= m or j >= n:
                return 10000000
            if i == m - 1 and j == n - 1:
                return grid[i][j]
            if dp[i][j] != 10000000:
                return dp[i][j]
            dp[i][j] = min(minPath(i+1,j),minPath(i,j+1)) + grid[i][j]
            return dp[i][j]
        return minPath(0,0)