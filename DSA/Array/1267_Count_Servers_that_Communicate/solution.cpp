// 1267. Count Servers that Communicate
// Difficulty : Medium
// Tags       : array, depth-first-search, breadth-first-search, union-find, matrix, counting
// Solved on  : 2019-11-29
// LeetCode   : https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r=grid.size();
        if(r==0){
            return 0;
        }
        int c=grid[0].size();
        vector<int> row(r,0),column(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    row[i]++;
                    column[j]++;
                }
            }
        }
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] && (row[i]>1 || column[j]>1)){
                    res++;
                }
            }
        }
        return res;
        
    }
};