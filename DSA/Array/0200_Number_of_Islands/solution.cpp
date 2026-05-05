// 0200. Number of Islands
// Difficulty : Medium
// Tags       : array, depth-first-search, breadth-first-search, union-find, matrix
// Solved on  : 2020-02-02
// LeetCode   : https://leetcode.com/problems/number-of-islands/

char mat[10010][10010];
int r,c;
int vis[10010][10010];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        r=grid.size();
        c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j]=grid[i][j];
                vis[i][j]=0;
            }
        }
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0 && mat[i][j]=='1'){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(int i,int j){
        if(i>=r || j>=c ||i<0 || j<0) return ;
        if(vis[i][j]) return;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ii=i+dx[k];
            int jj=j+dy[k];
            if(ii<r && ii>=0 && jj<c && jj>=0){
                if(mat[i][j]=='1'){
                    dfs(ii,jj);
                    
                }
            }
        }
        
    }
};