# 0001. Two Sum
# Difficulty : Easy
# Tags       : array, hash-table
# Solved on  : 2026-05-05
# LeetCode   : https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i,num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement],i]
            seen[num] = i
        
        