# 0121. Best Time to Buy and Sell Stock
# Difficulty : Easy
# Tags       : array, dynamic-programming
# Solved on  : 2026-05-06
# LeetCode   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn =  ((1 << 32) - 1)
        mx = - mn
        for i,x in enumerate(prices):
            mn = min(x,mn)
            mx = max(x-mn,mx)
        return mx
            