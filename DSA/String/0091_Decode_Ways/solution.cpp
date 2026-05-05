// 0091. Decode Ways
// Difficulty : Medium
// Tags       : string, dynamic-programming
// Solved on  : 2020-01-31
// LeetCode   : https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int dp[10010];
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        if(s[0]=='0') return 0;
        int x=f(0,s);
        return x;
    }
    int f(int i,string& s){
        if(i==s.length()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int x=f(i+1,s);
        
        if(i+1<s.length()){
            
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'7')){
                x+=f(i+2,s);
            }
        }
        return dp[i]=x;
        
    }
};