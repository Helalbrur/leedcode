// 0463. Island Perimeter
// Difficulty : Easy
// Tags       : array, depth-first-search, breadth-first-search, matrix
// Solved on  : 2020-02-01
// LeetCode   : https://leetcode.com/problems/island-perimeter/

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
class Solution {
public:
    int vis[110][110];
    int s=0;
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        for(int i=0;i<110;i++){
            for(int j=0;j<110;j++){
                vis[i][j]=false;
            }
        }
        int x=0,y=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        s+=4;
        dfs(x,y,grid);
        return s;
    }
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size()) return ;
        
        vis[i][j]=true;
        int c=0;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x<grid.size() && x>=0 && y>=0 && y<grid[0].size()){
                if(grid[x][y]==1){
                    c++;
                }
                if(vis[x][y]==false && grid[x][y]==1){
                    s+=4;
                   
                    dfs(x,y,grid);
                }
                
            }
        }
        s-=c;
    }
};