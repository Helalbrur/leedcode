// 0746. Min Cost Climbing Stairs
// Difficulty : Easy
// Tags       : array, dynamic-programming
// Solved on  : 2019-07-22
// LeetCode   : https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int dp[100000];
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,0,sizeof(dp));
        int a=df(cost,1);
         memset(dp,0,sizeof(dp));
        int b=df(cost,0);
        return min(a,b);
    }
    int df(vector<int>& cost,int n){
        if(n>=cost.size()){
            return 0;
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        dp[n]=min(df(cost,n+1)+cost[n],df(cost,n+2)+cost[n]);
        return dp[n];
    }
};