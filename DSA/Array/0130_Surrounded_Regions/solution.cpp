// 0130. Surrounded Regions
// Difficulty : Medium
// Tags       : array, depth-first-search, breadth-first-search, union-find, matrix
// Solved on  : 2019-11-23
// LeetCode   : https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        if(r>0){
            int c=board[0].size();
            bool vis[r+2][c+2];
            memset(vis,0,sizeof(vis));
            int dx[]={1,-1,0,0};
            int dy[]={0,0,-1,1};
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(board[i][j]=='O' && vis[i][j]==0){
                        bool ok=true;
                        vector<pair<int,int>> vec;
                        queue<pair<int,int>> q;
                        q.push(make_pair(i,j));
                        vis[i][j]=1;
                        vec.push_back(make_pair(i,j));
                        if((i==0 || i==r-1 || j==0 || j==c-1 ) && board[i][j]=='O'){
                            ok=false;
                            
                        }
                        while(!q.empty()){
                            pair<int,int> p=q.front();
                            int x=p.first;
                            int y=p.second;
                            
                            q.pop();
                            for(int k=0;k<4;k++){
                                int u=x+dx[k];
                                int v=y+dy[k];
                                if((u==0 && v<c && v>=0) || (v==0 && u<r && u>=0) ||(u==r-1 && v>=0 && v<c) || (v==c-1 && u>=0 && u<r)){
                                    
                                        if(board[u][v]=='O'){
                                            ok=false;
                                            //cout<<u<<" "<<v<<" "<<board[u][v]<<endl;
                                        }
                                        //cout<<u<<" "<<v<<endl;
                                    
                                }
                                if(u>=0 && u<r && v>=0 && v<c){
                                    if(board[u][v]=='O' && vis[u][v]==0){
                                        vec.push_back(make_pair(u,v));
                                        vis[u][v]=1;
                                        q.push(make_pair(u,v));
                                        //v.push_back(make_pair(u,v));
                                        
                                    }
                                }
                            }
                        }
                        if(ok==true){
                            for(int k=0;k<vec.size();k++){
                                board[vec[k].first][vec[k].second]='X';
                            }
                        }
                    }
                }
            }
            
        }
        return;
    }
};