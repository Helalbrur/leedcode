// 0785. Is Graph Bipartite?
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, union-find, graph
// Solved on  : 2020-02-13
// LeetCode   : https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    int vis[20010];
    int n;
    int to[20010],last[20010],nxt[20010];
    int edge=0;
    void init(){
        for(int i=0;i<20010;i++){
            last[i]=-1;
        }
    }
    void add(int u,int v){
        to[edge]=v;
        nxt[edge]=last[u];
        last[u]=edge++;
        
        to[edge]=u;
        nxt[edge]=last[v];
        last[v]=edge++;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0) return true;
        n=graph.size();
        init();
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int v=graph[i][j];
                add(i,v);
                n=max(n,max(i,v));
            }
        }
        
        for(int i=0;i<20010;i++){
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
        for(int j=last[i];j>=0;j=nxt[j]){
                int v=to[j];
                if(vis[v]==0){
                    if(vis[i]==1){
                        vis[v]=2;
                    }else{
                        vis[v]=1;
                    }
                    if(!dfs(v)) return false;
                }
                if(vis[i]==vis[v]) return false;
            
        }
         return true;
    }
   
};