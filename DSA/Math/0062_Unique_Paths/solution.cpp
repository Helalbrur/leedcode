// 0062. Unique Paths
// Difficulty : Medium
// Tags       : math, dynamic-programming, combinatorics
// Solved on  : 2020-02-04
// LeetCode   : https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int dp[110][110];
    int uniquePaths(int m, int n) {
        for(int i=0;i<110;i++){
            for(int j=0;j<110;j++){
                dp[i][j]=-1;
            }
        }
        return f(0,0,m,n);
    }
    int f(int i,int j,int m,int n){
        
        if(i>=m ||i<0 ||j>=n ||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return 1;
       return dp[i][j]=f(i+1,j,m,n)+f(i,j+1,m,n);
    }
};