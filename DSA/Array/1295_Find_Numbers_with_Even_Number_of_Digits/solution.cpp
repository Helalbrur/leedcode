// 1295. Find Numbers with Even Number of Digits
// Difficulty : Easy
// Tags       : array, math
// Solved on  : 2019-12-22
// LeetCode   : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int d=0;
            while(x){
                d++;
                x=x/10;
            }
            if(d%2==0){
                cnt++;
            }
        }
        return cnt;
        
    }
};