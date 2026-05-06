// 0121. Best Time to Buy and Sell Stock
// Difficulty : Easy
// Tags       : array, dynamic-programming
// Solved on  : 2019-07-23
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int mx=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mn){
                mn=prices[i];
               
            }
             mx=max(prices[i]-mn,mx);
           
        }
        return mx;
    }
    
};