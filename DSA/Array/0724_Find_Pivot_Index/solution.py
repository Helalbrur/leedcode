# 0724. Find Pivot Index
# Difficulty : Easy
# Tags       : array, prefix-sum
# Solved on  : 2022-07-07
# LeetCode   : https://leetcode.com/problems/find-pivot-index/

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        sum = 0 ;
        for i in range(0,len(nums),1):
            sum += nums[i];
        s = 0;
        for i in range(0,len(nums),1):
            if sum - s - nums[i] == s:
                return i;
            s += nums[i];
        return -1;
        