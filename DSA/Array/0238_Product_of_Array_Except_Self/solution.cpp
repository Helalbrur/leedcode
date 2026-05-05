// 0238. Product of Array Except Self
// Difficulty : Medium
// Tags       : array, prefix-sum
// Solved on  : 2019-08-13
// LeetCode   : https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        int L[len+3],R[len+3];
        vector<int> ans;
        L[0]=1;
        R[len-1]=1;
        for(int i=1;i<len;i++){
            L[i]=L[i-1]*nums[i-1];
        }
        for(int i=len-2;i>=0;i--){
            R[i]=R[i+1]*nums[i+1];
        }
        for(int i=0;i<len;i++){
            ans.push_back(L[i]*R[i]);
        }
        return ans;
    }
};