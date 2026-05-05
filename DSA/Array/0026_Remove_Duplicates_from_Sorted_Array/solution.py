# 0026. Remove Duplicates from Sorted Array
# Difficulty : Easy
# Tags       : array, two-pointers
# Solved on  : 2026-04-28
# LeetCode   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = list(dict.fromkeys(nums))
        return len(nums)
