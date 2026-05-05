# 0004. Median of Two Sorted Arrays
# Difficulty : Hard
# Tags       : array, binary-search, divide-and-conquer
# Solved on  : 2026-04-19
# LeetCode   : https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merge_arr = []
        i = j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                merge_arr.append(nums1[i])
                i += 1
            else:
                merge_arr.append(nums2[j])
                j += 1

        merge_arr.extend(nums1[i:])
        merge_arr.extend(nums2[j:])
        mid = len(merge_arr) // 2
        if len(merge_arr) % 2:
            return merge_arr[mid]
        else:
            return (merge_arr[mid] + merge_arr[mid-1]) / 2


