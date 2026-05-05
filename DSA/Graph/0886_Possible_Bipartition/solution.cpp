// 0886. Possible Bipartition
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, union-find, graph
// Solved on  : 2019-11-24
// LeetCode   : https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        vector<int> edge[N+2];
        for(int i=0;i<dislikes.size();i++){
            int x=dislikes[i][0];
            int y=dislikes[i][1];
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        int color[N+2];
        memset(color,0,sizeof(color));
        for(int i=1;i<=N;i++){
            if(color[i]==0){
                queue<int> q;
                color[i]=1;
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int j=0;j<edge[x].size();j++){
                        int y=edge[x][j];
                        if(color[y]==0){
                            if(color[x]==1){
                                color[y]=2;
                            }else{
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