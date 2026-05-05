# 0063. Unique Paths II
# Difficulty : Medium
# Tags       : array, dynamic-programming, matrix
# Solved on  : 2026-05-03
# LeetCode   : https://leetcode.com/problems/unique-paths-ii/

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m , n = len(obstacleGrid) ,len(obstacleGrid[0])
        @lru_cache(None)
        def dfs(i,j):
            if i >=m or j >=n:
                return 0
            if obstacleGrid[i][j] == 1:
                return 0
            if i == m-1 and j == n-1:
                return 1
            return dfs(i+1,j) + dfs(i,j+1)
        return dfs(0,0)
        