# 0001. Two Sum
# Difficulty : Easy
# Tags       : array, hash-table
# Solved on  : 2022-06-09
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(0,i):
                if(nums[i] + nums [j] == target):
                    return [j,i];
        