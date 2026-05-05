// 0121. Best Time to Buy and Sell Stock
// Difficulty : Easy
// Tags       : array, dynamic-programming
// Solved on  : 2019-08-13
// LeetCode   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                mx=max(mx,(prices[j]-prices[i]));
            }
        }
        return mx;
    }
    
   
};