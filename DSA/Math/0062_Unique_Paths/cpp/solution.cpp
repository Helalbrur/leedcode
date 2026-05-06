// 0062. Unique Paths
// Difficulty : Medium
// Tags       : math, dynamic-programming, combinatorics
// Solved on  : 2019-11-28
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int dp[110][110];
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,m,n);
    }
    int f(int i,int j,int m,int n){
        
        if(i>=m or j>=n){
            return 0;
         }
        if(i==m-1 and j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=f(i+1,j,m,n)+f(i,j+1,m,n);
    }
};