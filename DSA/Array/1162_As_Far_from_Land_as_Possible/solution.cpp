// 1162. As Far from Land as Possible
// Difficulty : Medium
// Tags       : array, dynamic-programming, breadth-first-search, matrix
// Solved on  : 2019-08-19
// LeetCode   : https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
         int dis[n+3][n+3];
        memset(dis,-1,sizeof(dis));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i,j));
                    dis[i][j]=0;
                }
                
            }
            
        }
       
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,-0};
        int ans=-1;
        //cout<<q.size()<<endl;
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            for(int i=0;i<4;i++){
                int u=r+dx[i];
                int v=c+dy[i];
                if(u>=n || v>=n ||u<0 || v<0 ||  dis[u][v]!=-1)
                    continue;
                dis[u][v]=dis[r][c]+1;
                ans=max(ans,dis[u][v]);
                q.push(make_pair(u,v));
            }
        }
        
        
        return ans;
    }
};