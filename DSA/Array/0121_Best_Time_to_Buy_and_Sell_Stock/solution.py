# 0121. Best Time to Buy and Sell Stock
# Difficulty : Easy
# Tags       : array, dynamic-programming
# Solved on  : 2026-05-06
# LeetCode   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        🔷 Step-by-Step Example
        prices = [7, 1, 5, 3, 6, 4]
        | Day | Price | min_price_so_far | Profit if sold today | max_profit |
        | --- | ----- | ---------------- | -------------------- | ---------- |
        | 0   | 7     | 7                | 0                    | 0          |
        | 1   | 1     | 1                | 0                    | 0          |
        | 2   | 5     | 1                | 4                    | 4          |
        | 3   | 3     | 1                | 2                    | 4          |
        | 4   | 6     | 1                | 5                    | 5          |
        | 5   | 4     | 1                | 3                    | 5          |
        """
        mn =  ((1 << 32) - 1)
        mx = - mn
        for i,x in enumerate(prices):
            mn = min(x,mn)
            mx = max(x-mn,mx)
        return mx
            