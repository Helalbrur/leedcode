# 0063. Unique Paths II
# Difficulty : Medium
# Tags       : array, dynamic-programming, matrix
# Solved on  : 2026-05-03
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/unique-paths-ii/

class Solution:
    def __init__(self):
        self.dp = [[-1 for _ in range(101)] for _ in range(101)]
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        return self.dfs(0,0,obstacleGrid)
    def dfs(self,i : int,j : int,obstacleGrid: List[List[int]]):
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        if i >=m or j >=n:
            return 0
        if obstacleGrid[i][j] == 1:
            return 0
        if i == m-1 and j == n-1:
            return 1
        if self.dp[i][j] !=-1:
            return self.dp[i][j]
        self.dp[i][j] = self.dfs(i+1,j,obstacleGrid) + self.dfs(i,j+1,obstacleGrid)
        return self.dp[i][j]
        