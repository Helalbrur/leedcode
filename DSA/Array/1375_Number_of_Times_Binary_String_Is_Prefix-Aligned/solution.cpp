// 1375. Number of Times Binary String Is Prefix-Aligned
// Difficulty : Medium
// Tags       : array
// Solved on  : 2020-03-08
// LeetCode   : https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int mn=INT_MIN;
        int cnt=0;
        for(int i=0;i<light.size();i++){
            mn=max(mn,light[i]);
            if(i+1==mn){
                cnt++;
            }
        } 
        return cnt;
    }
};