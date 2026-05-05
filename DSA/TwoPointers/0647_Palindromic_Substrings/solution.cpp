// 0647. Palindromic Substrings
// Difficulty : Medium
// Tags       : two-pointers, string, dynamic-programming
// Solved on  : 2019-12-20
// LeetCode   : https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
     int dp[1010][1010];
    int countSubstrings(string s) {
        
     for(int i=0;i<=s.length();i++){
            for(int j=0;j<=s.length();j++){
                dp[i][j]=-1;
            }
        }
        int mx=0, p=0;
        for(int i=0;i<s.length();i++){
            
            for(int j=i;j<s.length();j++){
                if(f(i,j,s)){
                    mx++;
                }
                
            }
        }
       return mx;
        
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