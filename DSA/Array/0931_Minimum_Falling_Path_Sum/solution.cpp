// 0931. Minimum Falling Path Sum
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2019-11-28
// LeetCode   : https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int dp[1010][1010];
    int minFallingPathSum(vector<vector<int>>& A) {
       memset(dp,-1,sizeof(dp));
        long long int mx=INT_MAX;
        for(int i=0;i<A[0].size();i++){
            mx=min(f(0,i,A),mx);
        }
        return mx;
        
        
    }
    long long int f(int i,int j,vector<vector<int>>& A){
        if(i>=A.size()){
            return INT_MAX;
        }
        if(i==A.size()-1){
            return A[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long int a=INT_MAX;
        int x=A[i][j];
        
       
        a=min(a,f(i+1,j,A)+x);
            
        
        if(j>0){
            a=min(a,f(i+1,j-1,A)+x);
        }
        if(j<A.size()-1){
            a=min(a,f(i+1,j+1,A)+x);
        }
        return dp[i][j]=a;
    }
};