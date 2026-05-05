// 1254. Number of Closed Islands
// Difficulty : Medium
// Tags       : array, depth-first-search, breadth-first-search, union-find, matrix
// Solved on  : 2019-11-12
// LeetCode   : https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int vis[r+102][c+102];
        memset(vis,0,sizeof(vis));
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int cnt=0;
         // for(int i=0;i<r;i++){
         //    for(int j=0;j<c;j++){
         //       cout<<grid[i][j]<<" ";
         //    }
         //    cout<<endl;
         // }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               
                if(grid[i][j]==0 && vis[i][j]==0 ){
                   
                   
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    bool ok =true;
                    vis[i][j]=1;
                   
                    while(!q.empty()){
                        int ur=q.front().first;
                        int uc=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int vr=dx[k]+ur;
                            int vc=dy[k]+uc;
                            if((vr==0 && (vc>=0 && vc<c)) || (vr==r-1 && (vc>=0 && vc<c)) || (vc==0 && (vr>=0 && vr<r)) || (vc==c-1 && (vr>=0 && vr<r))){
                                if(grid[vr][vc]==0 ){
                                   ok=false;
                                   vis[vr][vc]=1;
                                   //cout<<vr<<" "<<vc<<" "<<" Parent "<<i<<" "<<j<<endl;
                                   
                                }
                               
                                 
                            }else if(vr>0 && vr<r-1 && vc>0 && vc<c-1){
                                if(grid[vr][vc]==0){
                                    if(vis[vr][vc]==0){
                                        vis[vr][vc]=1;
                                        q.push(make_pair(vr,vc));
                                    }
                                    vis[vr][vc]=1;
                                    
                                 
                                   // cout<<vr<<" "<<vc<<" "<<" Parent "<<i<<" "<<j<<endl;
                                     
                                }
                            }
                        }
                    }
                     if(i==0 || i==r-1 || j==0 || j==c-1){
                        continue;
                    }
                    if(ok==true){
                       // cout<<"_____"<<grid[i][j]<<" "<<i<<" "<<j<<"_______"<<endl;
                        cnt++;
                    }
                }
            }
           
            
        }
        return cnt;
        
    }
};