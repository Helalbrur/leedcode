// 0121. Best Time to Buy and Sell Stock
// Difficulty : Easy
// Tags       : array, dynamic-programming
// Solved on  : 2026-05-06
// LeetCode   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    /*🔷 Step-by-Step Example
        prices = [7, 1, 5, 3, 6, 4]
        | Day | Price | min_price_so_far | Profit if sold today | max_profit |
        | --- | ----- | ---------------- | -------------------- | ---------- |
        | 0   | 7     | 7                | 0                    | 0          |
        | 1   | 1     | 1                | 0                    | 0          |
        | 2   | 5     | 1                | 4                    | 4          |
        | 3   | 3     | 1                | 2                    | 4          |
        | 4   | 6     | 1                | 5                    | 5          |
        | 5   | 4     | 1                | 3                    | 5          |
    */
    var mn = Number.MAX_SAFE_INTEGER;
    var mx = - mn;
    prices.forEach((p,indx,arr)=>{
        mn = Math.min(p,mn);
        mx = Math.max(p-mn,mx);
    });
    return mx;
};