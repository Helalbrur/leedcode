// 0238. Product of Array Except Self
// Difficulty : Medium
// Tags       : array, prefix-sum
// Solved on  : 2019-08-13
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
         vector<int> output;
        int mul=1;
        int c=0,p=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c++;
                p=i;
            }else{
                mul*=nums[i];
            }
            
        }
        if(c>1)
        {
            for(int i=0;i<nums.size();i++){
                output.push_back(0);
            }
        }else if(c==1){
           for(int i=0;i<nums.size();i++){
               if(i==p){
                  
                    output.push_back(mul);
               }else{
                   output.push_back(0);
               }
                
            } 
        }else{
             for(int i=0;i<nums.size();i++){
               
                 output.push_back(mul/nums[i]);
               
                
            } 
        }
        
        return output;
    }
};