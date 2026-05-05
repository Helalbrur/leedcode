// 0053. Maximum Subarray
// Difficulty : Medium
// Tags       : array, divide-and-conquer, dynamic-programming
// Solved on  : 2019-07-15
// LeetCode   : https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int sz;
    int dp[1000000];
    int maxSubArray(vector<int>& nums) {
        
        sz=nums.size();
        
      /*  for(int i=0;i<sz;i++){
            dp[i]=nums[i];
        }
        return df(sz);
        */
        int max_sum=INT_MIN,end_sum=0;
        for(int i=0;i<sz;i++){
            end_sum+=nums[i];
            if(end_sum>max_sum){
                max_sum=end_sum;
            }
            if(end_sum<0){
                end_sum=0;
            }
        }
        return max_sum;
    }
     
    int df(int i){
        int w=0;
        if(i==0){
            return w;
        }
        int m1=df(i-1)+dp[i];
        int m2=dp[i];
        w=max(m1,m2);
        if(w<0){
            w=0;
        }
        return w;
    }
};