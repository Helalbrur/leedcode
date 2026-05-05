// 0287. Find the Duplicate Number
// Difficulty : Medium
// Tags       : array, two-pointers, binary-search, bit-manipulation
// Solved on  : 2019-11-28
// LeetCode   : https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return 1;
    }
};