// 1480. Running Sum of 1d Array
// Difficulty : Easy
// Tags       : array, prefix-sum
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0 ;
        for (int i = 0 ; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
        
    }
};