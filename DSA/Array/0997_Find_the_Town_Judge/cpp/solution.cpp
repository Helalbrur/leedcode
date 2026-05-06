// 0997. Find the Town Judge
// Difficulty : Easy
// Tags       : array, hash-table, graph
// Solved on  : 2019-07-23
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1)
            return 1;
        int dp[N+2];
        int d[N+2];
        memset(dp,0,sizeof(dp));
        memset(d,0,sizeof(d));
        for(int i=0;i<trust.size();i++){
            dp[trust[i][1]]++;
            d[trust[i][0]]++;
        }
        for(int i=0;i<=N;i++){
            if(dp[i]>=N-1 && d[i]==0){
                return i;
            }
        }
        return -1;
        
    }
};