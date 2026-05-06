// 0785. Is Graph Bipartite?
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, union-find, graph
// Solved on  : 2020-02-04
// Attempt    : #3
// LeetCode   : https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    int mat[111][111];
    int vis[111];
    int n;
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0) return true;
        n=graph.size();
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int v=graph[i][j];
                mat[i][v]=1;
                mat[v][i]=1;
                n=max(n,max(i,v));
            }
        }
        
        for(int i=0;i<=n;i++){
            vis[i]=0;
        }
        for(int i=0;i<=n;i++){
            if(vis[i]==0){
                vis[i]=1;
                if(!dfs(i)) return false; 
            }
        }
        return true;
    }
    bool dfs(int i){
        for(int j=0;j<=n;j++){
            if(mat[i][j]==1){
                if(vis[j]==0){
                    if(vis[i]==1){
                        vis[j]=2;
                    }else{
                        vis[j]=1;
                    }
                    if(!dfs(j)) return false;
                }
                if(vis[i]==vis[j]) return false;
            }
        }
         return true;
    }
   
};