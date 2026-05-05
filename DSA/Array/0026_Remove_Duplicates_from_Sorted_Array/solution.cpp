// 0026. Remove Duplicates from Sorted Array
// Difficulty : Easy
// Tags       : array, two-pointers
// Solved on  : 2020-04-20
// LeetCode   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=1;
        if(nums.size()==1 || nums.size()==0) return nums.size();
        int i=1;
        while(i<nums.size()){
            if(nums[i]!=nums[i-1]){
                len++;
                i++;
            }else{
                nums.erase(nums.begin()+i);
            }  
        }
        return len;
    }
};