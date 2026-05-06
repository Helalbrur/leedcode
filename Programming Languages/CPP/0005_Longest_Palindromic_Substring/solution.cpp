// 0005. Longest Palindromic Substring
// Difficulty : Medium
// Tags       : two-pointers, string, dynamic-programming
// Solved on  : 2019-12-20
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int dp[1010][1010];
    string longestPalindrome(string s) {
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=s.length();j++){
                dp[i][j]=-1;
            }
        }
        int mx=0, p=0;
        for(int i=0;i<s.length();i++){
            
            for(int j=i;j<s.length();j++){
                if(f(i,j,s)){
                    mx=max(mx,j-i+1);
                    if(j-i+1>=mx){
                        mx=j-i+1;
                        p=i;
                    }
                }
                
            }
        }
        return s.substr(p,mx);
        
    }
    bool f(int i,int j,string& s){
        if(i>=j)
            return true;
        if(s[i]!=s[j])
            return false;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=f(i+1,j-1,s);
    }
    
};