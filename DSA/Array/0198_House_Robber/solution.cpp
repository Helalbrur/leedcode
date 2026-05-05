// 0198. House Robber
// Difficulty : Medium
// Tags       : array, dynamic-programming
// Solved on  : 2019-07-23
// LeetCode   : https://leetcode.com/problems/house-robber/

class Solution {
public:
    int dp[100000];
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return df(nums,0);
    }
    int df(vector<int>& nums,int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
            
        }
        dp[i]=max(df(nums,i+2)+nums[i],df(nums,i+1));
        return dp[i];
    }
};