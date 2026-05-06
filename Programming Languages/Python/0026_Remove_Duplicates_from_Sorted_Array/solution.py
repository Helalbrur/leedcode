# 0026. Remove Duplicates from Sorted Array
# Difficulty : Easy
# Tags       : array, two-pointers
# Solved on  : 2026-04-28
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0 or len(nums) == 1:
            return len(nums)
        ln = 1
        i = 1
        while i < len(nums):
            if nums[i] != nums[i-1]:
                i+=1
                ln+=1
            else:
                nums.pop(i)
        return ln
