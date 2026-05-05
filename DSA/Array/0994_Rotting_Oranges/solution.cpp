// 0994. Rotting Oranges
// Difficulty : Medium
// Tags       : array, breadth-first-search, matrix
// Solved on  : 2019-12-01
// LeetCode   : https://leetcode.com/problems/rotting-oranges/

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
public:
    int dp[12][12];
    bool visit[12][12];
    int orangesRotting(vector<vector<int>>& grid) {
       
        int mx=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    for(int x=0;x<=10;x++){
                        for(int y=0;y<=10;y++){
                            dp[x][y]=1000;
                            
                        }
                    }
                    
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    bool ok=false;
                    int d=0;
                    dp[i][j]=0;
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        int u=p.first;
                        int v=p.second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int x=u+dx[k];
                            int y=v+dy[k];
                            if(isValid(x,y,grid)){
                                
                                if(dp[x][y]>dp[u][v]+1){
                                    dp[x][y]=dp[u][v]+1;
                                    q.push({x,y});
                                    
                                }
                                if(grid[x][y]==2){
                                    ok=true;
                                    d=dp[x][y];
                                    break;
                                }
                                //cout<<x<<"__"<<y<<"__dis__"<<dp[x][y]<<"__from__"<<u<<"__"<<v<<"__dis__"<<dp[u][v]<<endl;
                            }
                        }
                        if(ok==true){
                            break;
                        }
                    }
                    if(ok==false){
                        return -1;
                    }
                   mx=max(mx,d);
                    
                }
            }
        }
       
       
        return mx;
        
    }
    bool isValid(int i,int j,vector<vector<int>>& grid){
       
        int r=grid.size();
         if(i<0 || i>=r || j<0){
             return false;
         }
        if(j>=grid[i].size()){
            return false;
        }
        
        if(grid[i][j]!=0){
            
             return true;
        }
           
       
        return false;
    }
   
};