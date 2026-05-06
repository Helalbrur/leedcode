# 0062. Unique Paths
# Difficulty : Medium
# Tags       : math, dynamic-programming, combinatorics
# Solved on  : 2026-04-30
# Attempt    : #2
# LeetCode   : https://leetcode.com/problems/unique-paths/

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return self.upath(0,0,m,n);
    @lru_cache(None)
    def upath(self,i:int,j:int,m:int,n:int):
        if i >=m or j >=n:
            return 0  
        if i == m-1 and j == n-1:
            return 1
        return self.upath(i+1,j,m,n) + self.upath(i,j+1,m,n)