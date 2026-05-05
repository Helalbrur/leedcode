// 0724. Find Pivot Index
// Difficulty : Easy
// Tags       : array, prefix-sum
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            sum += nums[i];
        }
        int s = 0;
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            if( sum - s - nums[i] == s ) return i;
            s += nums[i];
        }
        return -1;
    }
};