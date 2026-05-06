// 0785. Is Graph Bipartite?
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, union-find, graph
// Solved on  : 2020-02-02
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    int n=0;
    int a[110][110];
    int color[110];
    bool isBipartite(vector<vector<int>>& graph) {
      if(graph.size()==0) return true;
      
      for(int i=0;i<graph.size();i++){
          for(int j=0;j<graph[i].size();j++){
              int x=graph[i][j];
              a[i][x]=1;
              a[x][i]=1;
              n=max(max(x,i),n);
          }
      }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
      
        
      return isBipartite(); 
    }
   
   bool isBipartite(){
       for(int i=0;i<=n;i++){
           if(color[i]==0){
               color[i]=1;
               if(dfs(i)==false){
                   cout << i << ": false\n";
                   return false;
               }
           }
       }
       return true;
   }
   bool dfs(int u){
       for(int i=0;i<=n;i++){
           if(a[u][i]==1){
               if(color[i]==0){
                   if(color[u]==1){
                       color[i]=2;
                   }else if(color[u]==2){
                       color[i]=1;
                   }else{
                       cout<<"Wrong"<<endl;
                   }
                   
                   bool res = dfs(i);
                   if(res==false) return false;
               }
               if(color[u]==color[i]){ 
                   cout<<u<<" : "<<color[u]<<" __ "<<i<<" : "<<color[i]<<endl;
                   return false;
               }
           }
       }
       return true;
   }
    
};