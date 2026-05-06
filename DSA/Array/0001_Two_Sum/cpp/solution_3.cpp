// 0001. Two Sum
// Difficulty : Easy
// Tags       : array, hash-table
// Solved on  : 2026-04-19
// Attempt    : #3
// LeetCode   : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 1 ;i<nums.size();i++)
        {
            for(int j = 0 ; j<i; j++){
                if(target - nums[j] == nums[i]) {
                 res.push_back(j); 
                 res.push_back(i);  
                 return res;  
                }
            }
        }
        return res;
    }
};