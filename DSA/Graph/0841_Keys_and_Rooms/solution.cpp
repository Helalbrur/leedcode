// 0841. Keys and Rooms
// Difficulty : Medium
// Tags       : depth-first-search, breadth-first-search, graph
// Solved on  : 2019-11-29
// LeetCode   : https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int vis[n+3];
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            
            int u=q.front();
            q.pop();
            for(int i=0;i<rooms[u].size();i++){
                int v=rooms[u][i];
                if(vis[v]==0){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};