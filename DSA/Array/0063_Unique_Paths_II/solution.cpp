// 0063. Unique Paths II
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2019-11-28
// LeetCode   : https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int dp[110][110];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,obstacleGrid);
    }
    
    int f(int i,int j,vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();
        int n=0;
        if(m>0){
            n=obstacleGrid[0].size();
        }
        
        if(i>=m or j>=n){
            return 0;
         }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 and j==n-1 && obstacleGrid[i][j]!=1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        if(i+1 <m && j<n && obstacleGrid[i+1][j]!=1){
            a+=f(i+1,j,obstacleGrid);
        }
        if(i <m && j+1<n && obstacleGrid[i][j+1]!=1){
            a+=f(i,j+1,obstacleGrid);
        }
        
        return dp[i][j]=a;
    }
};