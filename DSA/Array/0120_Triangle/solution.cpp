// 0120. Triangle
// Difficulty : Medium
// Tags       : array, dynamic-programming
// Solved on  : 2019-11-28
// LeetCode   : https://leetcode.com/problems/triangle/

class Solution {
public:
    int dp[1010][1010];
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,triangle);
        
    }
    long long int f(int i,int j,vector<vector<int>>& triangle){
        if(i>=triangle.size()){
            return INT_MAX;
        }
        int row=triangle.size();
        int col=0;
        if(triangle.size()>0){
            col=triangle[i].size();
        }
        if(j>=col){
            return INT_MAX;
        }
        if(i==row-1 && j<col){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=min(f(i+1,j,triangle)+triangle[i][j],f(i+1,j+1,triangle)+triangle[i][j]);
    }
};