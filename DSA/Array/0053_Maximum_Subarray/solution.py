# 0053. Maximum Subarray
# Difficulty : Medium
# Tags       : array, divide-and-conquer, dynamic-programming
# Solved on  : 2026-04-28
# LeetCode   : https://leetcode.com/problems/maximum-subarray/

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        current_sub_array_sum = 0
        best_sum = nums[0]
        for i,x in enumerate(nums):
            current_sub_array_sum = max(x,current_sub_array_sum + x)
            best_sum = max(current_sub_array_sum,best_sum)
        return best_sum