# 0977. Squares of a Sorted Array
# Difficulty : Easy
# Tags       : array, two-pointers, sorting
# Solved on  : 2026-05-14
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums = [n * n for n in nums]
        nums.sort();
        return nums;