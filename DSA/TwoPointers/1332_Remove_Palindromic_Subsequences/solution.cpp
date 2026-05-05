// 1332. Remove Palindromic Subsequences
// Difficulty : Easy
// Tags       : two-pointers, string
// Solved on  : 2020-01-31
// LeetCode   : https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    int removePalindromeSub(string s) {
     if(s=="")
         return 0;
      string a=s;
      reverse(s.begin(),s.end());
     if(s==a){
         return 1;
     }
     return 2;
    }
};