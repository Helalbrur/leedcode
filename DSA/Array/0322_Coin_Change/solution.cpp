// 0322. Coin Change
// Difficulty : Medium
// Tags       : array, dynamic-programming, breadth-first-search
// Solved on  : 2020-02-01
// LeetCode   : https://leetcode.com/problems/coin-change/

class Solution {
public:
    int dp[100010];
    int m=INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        for(int i=0;i<100010;i++){
            dp[i]=-1;
        }
        for(int i=0;i<coins.size();i++){
            m=min(m,coins[i]);
        }
        int x= f(coins,amount);
        return x>=100000 ? -1 : x;
    }
    int f(vector<int>& coins, int amount){
        if(amount==0) return 0;
        if(amount<m) return 100000;
        if(dp[amount]!=-1) return dp[amount];
        int x=INT_MAX;
       
        for(int i=0;i<coins.size();i++){
            m=min(m,coins[i]);
            if(amount>=coins[i]){
                x=min(x,f(coins,amount-coins[i])+1);
            }
        }
        return dp[amount]=x;
    }
};