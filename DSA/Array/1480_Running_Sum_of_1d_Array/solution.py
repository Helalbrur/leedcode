# 1480. Running Sum of 1d Array
# Difficulty : Easy
# Tags       : array, prefix-sum
# Solved on  : 2022-07-07
# LeetCode   : https://leetcode.com/problems/running-sum-of-1d-array/

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sum = 0 
        for x in range (0,len(nums),1):
            sum+= nums[x];
            nums[x] = sum;
        return nums;