# 0062. Unique Paths
# Difficulty : Medium
# Tags       : math, dynamic-programming, combinatorics
# Solved on  : 2026-04-30
# Attempt    : #3
# LeetCode   : https://leetcode.com/problems/unique-paths/

class Solution:
    def __init__(self):
        self.dp = [ [ -1 for _ in range(101)] for _ in range(101)]
    
    def uniquePaths(self, m: int, n: int) -> int:
        return self.upath(0,0,m,n);
        
    def upath(self,i:int,j:int,m:int,n:int):
        if i >=m or j >=n:
            return 0
        if self.dp[i][j] != -1:
            return self.dp[i][j]
            
        if i == m-1 and j == n-1:
            return 1
        self.dp[i][j] = self.upath(i+1,j,m,n) + self.upath(i,j+1,m,n)
        return self.dp[i][j]