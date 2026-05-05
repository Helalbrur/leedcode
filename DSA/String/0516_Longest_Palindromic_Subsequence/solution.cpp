// 0516. Longest Palindromic Subsequence
// Difficulty : Medium
// Tags       : string, dynamic-programming
// Solved on  : 2019-12-20
// LeetCode   : https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int dp[1010][1010];
    int longestPalindromeSubseq(string s) {
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=s.length();j++){
                dp[i][j]=-1;
            }
        }
        return f(0,s.length()-1,s);
        
    }
    int f(int i,int j,string& s){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            dp[i][j]=f(i+1,j-1,s)+2;
        }else{
            dp[i][j]=max(f(i,j-1,s),f(i+1,j,s));
        }
       return dp[i][j];
    }
};