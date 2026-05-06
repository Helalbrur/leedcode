# 0053. Maximum Subarray
# Difficulty : Medium
# Tags       : array, divide-and-conquer, dynamic-programming
# Solved on  : 2026-04-28
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/maximum-subarray/

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s = 0
        mx = - ( (1 << 31) -1)
        for i,x in enumerate(nums):
            s +=x
            if s > mx :
                mx = s
            if s < 0:
                s = 0
        return mx