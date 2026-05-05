// 0221. Maximal Square
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2020-02-01
// LeetCode   : https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size();
        if(r==0) return 0;
        int c=matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        int s=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(!i || !j || matrix[i][j]=='0') dp[i][j]=matrix[i][j]-'0';
                else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                s=max(s,dp[i][j]);
            }
        }
        return s*s;
        
    }
};