// 0338. Counting Bits
// Difficulty : Easy
// Tags       : dynamic-programming, bit-manipulation
// Solved on  : 2019-07-23
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/counting-bits/

class Solution {
public:
    int dp[100000];
    vector<int> countBits(int num) {
        memset(dp,-1,sizeof(dp));
        vector<int> vec;
        for(int i=0;i<=num;i++){
            vec.push_back(countSetBit(i));
        }
        return vec;
        
    }
    int countSetBit(int n){
        if(dp[n]!=-1){
            return dp[n];
        }
        int t=n,cnt=0;
        while(n){
            cnt+=n & 1;
            n=n>>1;
        }
        return dp[t]=cnt;
    }
};