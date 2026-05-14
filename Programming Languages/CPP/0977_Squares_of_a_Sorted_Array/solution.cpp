// 0977. Squares of a Sorted Array
// Difficulty : Easy
// Tags       : array, two-pointers, sorting
// Solved on  : 2026-05-14
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            nums[i] = x * x;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};