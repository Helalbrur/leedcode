// 0070. Climbing Stairs
// Difficulty : Easy
// Tags       : math, dynamic-programming, memoization
// Solved on  : 2019-07-22
// LeetCode   : https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int dp[10000];
    int climbStairs(int n) {
        memset(dp,0,sizeof(dp));
        return df(n);
    }
    int df(int n){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        return dp[n]=df(n-2)+df(n-1);
    }
};