// 0001. Two Sum
// Difficulty : Easy
// Tags       : array, hash-table
// Solved on  : 2026-04-23
// LeetCode   : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> mp;
        for(int i = 0 ;i<nums.size();i++)
        {
            int num = nums[i];
            int complement = target - num;
            if (mp.find(complement) != mp.end()){
                res.push_back(mp[complement]);
                res.push_back(i);
                return res;
            }
            mp[num] = i;
        }
        return res;
    }
};