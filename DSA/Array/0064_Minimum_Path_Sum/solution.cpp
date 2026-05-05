// 0064. Minimum Path Sum
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2019-11-28
// LeetCode   : https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int dp[1100][1100];
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,grid);
    }
    
    int f(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=0;
        if(m>0){
            n=grid[0].size();
        }
        
        if(i>=m or j>=n){
            return 10000;
         }
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       
        return dp[i][j]=min(f(i+1,j,grid)+grid[i][j],f(i,j+1,grid)+grid[i][j]);
    }
};