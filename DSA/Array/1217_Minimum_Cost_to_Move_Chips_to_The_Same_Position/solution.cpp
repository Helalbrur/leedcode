// 1217. Minimum Cost to Move Chips to The Same Position
// Difficulty : Easy
// Tags       : array, math, greedy
// Solved on  : 2019-10-06
// LeetCode   : https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int cnt=INT_MAX;
        for(int i=0;i<chips.size();i++){
            int mx=0;
            for(int j=0;j<chips.size();j++){
                int a=chips[i];
                int b=chips[j];
                int dis=abs(a-b);
                mx+=dis%2;
                
            }
            cnt=min(cnt,mx);
        }
        return cnt;
    }
};