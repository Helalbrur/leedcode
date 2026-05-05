# 0238. Product of Array Except Self
# Difficulty : Medium
# Tags       : array, prefix-sum
# Solved on  : 2019-08-13
# LeetCode   : https://leetcode.com/problems/product-of-array-except-self/

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length=len(nums)
        L=[0]*length
        R=[0]*length
        Output=[0]* length
        L[0]=1
        for i in range(1,length):
            L[i]=L[i-1]*nums[i-1]
        R[length-1]=1
        for i in reversed(range(length-1)):
            R[i]=R[i+1]*nums[i+1]
        
        for i in range(length):
            Output[i]=L[i]*R[i]
        return Output
            
        