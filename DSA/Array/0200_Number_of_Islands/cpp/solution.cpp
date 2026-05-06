// 0200. Number of Islands
// Difficulty : Medium
// Tags       : array, depth-first-search, breadth-first-search, union-find, matrix
// Solved on  : 2019-11-23
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int r,c;
    
    int numIslands(vector<vector<char>>& grid) {
        
        r=grid.size();
        if(r==0)
            return 0;
        c=grid[0].size();
        bool vis[r+2][c+2];
        memset(vis,0,sizeof(vis));
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    vis[i][j]=1;
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        int x=p.first;
                        int y=p.second;
                        for(int k=0;k<4;k++){
                            int u=x+dx[k];
                            int v=y+dy[k];
                            if(u>=0 && u<r && v>=0 && v<c ){
                                if(vis[u][v]==0 && grid[u][v]=='1'){
                                    q.push(make_pair(u,v));
                                     vis[u][v]=1;
                                }
                                
                            }
                            
                        }
                    }
                }
            }
        }
        return cnt;
        
        
    }
};