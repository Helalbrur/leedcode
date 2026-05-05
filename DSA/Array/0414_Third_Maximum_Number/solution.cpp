// 0414. Third Maximum Number
// Difficulty : Easy
// Tags       : array, sorting
// Solved on  : 2019-08-27
// LeetCode   : https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int f=LONG_MIN,s=LONG_MIN,t=LONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>f){
                t=s;
                s=f;
                f=nums[i];
            
            }else if(nums[i]>s && nums[i]!=f){
                t=s;
                s=nums[i];
            }else if(nums[i]>t && nums[i]!=f && nums[i]!=s){
                t=nums[i];
            }
        }
      
        if(t==LONG_MIN){
            return f;
        }else{
            return t;
        }
        
    }
};