// 1128. Number of Equivalent Domino Pairs
// Difficulty : Easy
// Tags       : array, hash-table, counting
// Solved on  : 2019-08-24
// LeetCode   : https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int cnt=0;
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++)
        {
            
            int sum=dominoes[i][1]+dominoes[i][0];
            int sub=abs(dominoes[i][1]-dominoes[i][0]);
           
            mp[make_pair(sum,sub)]++;
            cnt+=mp[make_pair(sum,sub)]-1;
            
           
           
            
        }
        
        return cnt;
    }
};