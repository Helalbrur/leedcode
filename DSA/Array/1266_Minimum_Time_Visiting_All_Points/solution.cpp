// 1266. Minimum Time Visiting All Points
// Difficulty : Easy
// Tags       : array, math, geometry
// Solved on  : 2019-11-24
// LeetCode   : https://leetcode.com/problems/minimum-time-visiting-all-points/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dis=0;
        for(int i=1;i<points.size();i++){
            int x=points[i-1][0];
            int y=points[i-1][1];
            int u=points[i][0];
            int v=points[i][1];
            dis+=max(abs(u-x),abs(y-v));
            
        }
        return dis;
        
    }
};