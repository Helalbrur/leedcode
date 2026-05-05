// 0392. Is Subsequence
// Difficulty : Easy
// Tags       : two-pointers, string, dynamic-programming
// Solved on  : 2019-10-11
// LeetCode   : https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        return dp(s,t,0,0);
    }
    bool dp(string &s,string &t,int i,int j){
        if(i>=s.length()){
            return true;
        }
        if(j>=t.length()){
            return false;
        }
        bool r=false;
        if(s[i]==t[j]){
            r=dp(s,t,i+1,j+1);
        }else{
            r=dp(s,t,i,j+1);
        }
        return r;
    }
};