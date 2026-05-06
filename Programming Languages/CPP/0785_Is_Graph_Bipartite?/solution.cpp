// 0785. Is Graph Bipartite?
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, union-find, graph
// Solved on  : 2019-11-24
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v[n+2];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                v[i].push_back(graph[i][j]);
            }
        }
        int color[n+3];
        memset(color,0,sizeof(color));
        for(int i=0;i<n;i++){
            if(color[i]==0){
                
                queue<int> q;
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int j=0;j<v[x].size();j++){
                        int y=v[x][j];
                        if(color[y]==0){
                            if(color[x]==1){
                                color[y]=2;
                            }else if(color[x]==2){
                                color[y]=1;
                            }
                            q.push(y);
                        }

                        if(color[x]==color[y]){
                            return false;
                        }
                        
                    }
                }
                
            }
          

        }
        return true;
    }
};