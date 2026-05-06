# 0001. Two Sum
# Difficulty : Easy
# Tags       : array, hash-table
# Solved on  : 2026-04-19
# Attempt    : #2
# LeetCode   : https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = []
        for i in range(0,len(nums)):
            for j in range (i+1,len(nums)):
                if ( target - nums[i]) == nums[j]:
                    res.append(i)
                    res.append(j)
                    return res
        return res;
        