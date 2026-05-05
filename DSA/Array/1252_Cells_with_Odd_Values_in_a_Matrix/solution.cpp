// 1252. Cells with Odd Values in a Matrix
// Difficulty : Easy
// Tags       : array, math, simulation
// Solved on  : 2019-11-10
// LeetCode   : https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int a[n+2][m+2];
        memset(a,0,sizeof(a));
        for(int i=0;i<indices.size();i++){
            
            int r=indices[i][0];
            int c=indices[i][1];
            for(int i=0;i<n;i++){
                a[i][c]++;
            }
            for(int i=0;i<m;i++){
                a[r][i]++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]%2){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};