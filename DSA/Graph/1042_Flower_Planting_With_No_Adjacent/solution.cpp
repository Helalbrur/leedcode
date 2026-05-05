// 1042. Flower Planting With No Adjacent
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, graph
// Solved on  : 2019-11-26
// LeetCode   : https://leetcode.com/problems/flower-planting-with-no-adjacent/

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> edge[N+2];
        for(int i=0;i<paths.size();i++){
            int x=paths[i][0];
            int y=paths[i][1];
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        int color[N+2];
        memset(color,0,sizeof(color));
        for(int i=1;i<=N;i++){
            if(color[i]==0){
                queue<int> q;
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int j=0;j<edge[x].size();j++){
                        int y=edge[x][j];
                        
                        if(color[y]==0){
                            int p[5];
                            memset(p,0,sizeof(p));
                            for(int k=0;k<edge[y].size();k++){
                                if(color[edge[y][k]]>0){
                                    p[color[edge[y][k]]]=1;
                                }
                            }
                            for(int h=1;h<=4;h++){
                                if(p[h]==0){
                                    color[y]=h;
                                    break;
                                }
                            }
                            
                            q.push(y);
                        }
                    }
                }
            }
        }
        vector<int> v;
        for(int i=1;i<=N;i++){
            v.push_back(color[i]);
        }
        return v;
    }
};