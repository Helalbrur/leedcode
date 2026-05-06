# 0004. Median of Two Sorted Arrays
# Difficulty : Hard
# Tags       : array, binary-search, divide-and-conquer
# Solved on  : 2026-04-19
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merge_arr = []
        i = 0
        j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                merge_arr.append(nums1[i])
                i = i + 1
            else:
                merge_arr.append(nums2[j])
                j = j + 1

        while i < len(nums1):
            merge_arr.append(nums1[i])
            i = i + 1
        
        while j < len(nums2):
            merge_arr.append(nums2[j])
            j = j + 1
        total_length = len(merge_arr)
        sencod_index = total_length // 2
        #print(merge_arr,sencod_index)
        if total_length % 2 == 0:
            first_index = sencod_index - 1
            return (merge_arr[first_index] + merge_arr[sencod_index]) / 2
        else:
            return merge_arr[sencod_index]


