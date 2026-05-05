// 0695. Max Area of Island
// Difficulty : Medium
// Tags       : array, depth-first-search, breadth-first-search, union-find, matrix
// Solved on  : 2019-12-02
// LeetCode   : https://leetcode.com/problems/max-area-of-island/

int r,c;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[1010][1010];
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt=max(dfs(i,j,grid,1),cnt);
                   
                }
            }
        }
        return cnt;
        
    }
    
       bool isValid(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size()){
            return false;
        }
        if(j>=grid[i].size()){
            return false;
        }
        if(vis[i][j]==1 || grid[i][j]==0){
            return false;
        }
        return true;
    }
    int  dfs(int i,int j,vector<vector<int>>& grid,int cnt){
       if(!isValid(i,j,grid)){
           return cnt;
       }
        vis[i][j]=true;
        
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(isValid(x,y,grid)){
               cnt=max(cnt, dfs(x,y,grid,cnt+1));
            }
        }
        return cnt;
    }
};