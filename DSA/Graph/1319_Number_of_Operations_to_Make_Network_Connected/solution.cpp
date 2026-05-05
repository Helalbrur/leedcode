// 1319. Number of Operations to Make Network Connected
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, union-find, graph
// Solved on  : 2020-01-12
// LeetCode   : https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
         if(connections.size()<n-1){
             return -1;
         }  
        bool vis[100010];
        memset(vis,0,sizeof(vis));
        vector<int> a[n+2];
        for(int i=0;i<connections.size();i++){
            int u,v;
            u=connections[i][0];
            v=connections[i][1];
            cout<<u<<" "<<v<<endl;
            a[u].push_back(v);
            a[v].push_back(u);
        }
         int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    for(int j=0;j<a[u].size();j++){
                        int v=a[u][j];
                        if(vis[v]==0){
                            q.push(v);
                            vis[v]=1;
                        }
                    }
                }
            }
        }
        return cnt-1;
    
    }
};