// 0639. Decode Ways II
// Difficulty : Hard
// Tags       : string, dynamic-programming
// Solved on  : 2020-01-31
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/decode-ways-ii/

class Solution {
public:
    int dp[100100];
    int m=1e9+7;
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s);
    }
    int f(int i,string& s){
        if(i==s.length()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int x=f(i+1,s)%m;
        if(s[i]=='*') x=(x*1LL*9)%m;
        if(i+1==s.length()) return dp[i]=x;
        for(char c1=s[i]=='*'?'1':s[i];c1<=(s[i]=='*'?'9':s[i]);c1++){
            for(char c2=s[i+1]=='*'?'1':s[i+1];c2<=(s[i+1]=='*'?'9':s[i+1]);c2++){
                int p=(c1-'0')*10+c2-'0';
                if(p<27){
                    x=(x+f(i+2,s))%m;
                }
            }
        }
        return dp[i]=x;
    }
};