// 0733. Flood Fill
// Difficulty : Easy
// Tags       : array, depth-first-search, breadth-first-search, matrix
// Solved on  : 2020-02-01
// LeetCode   : https://leetcode.com/problems/flood-fill/

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
class Solution {
public:
    
    int source_color=0;
    bool vis[55][55];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int r=image.size();
        if(r==0) return image;
        int c=image[0].size();
        
        for(int i=0;i<55;i++){
            for(int j=0;j<55;j++){
                vis[i][j]=false;
            }
        }
        source_color=image[sr][sc];
        image[sr][sc]=newColor;
        dfs(sr,sc,newColor,image);
        return image;
    }
    void dfs(int i,int j,int c,vector<vector<int>>& image){
        if(i>= image.size() || i<0 || j<0 || j>=image[0].size()) return;
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x<image.size() && x>=0 && y>=0 && y<image[0].size()){
                if(vis[x][y]==false){
                    if(image[x][y]==source_color){
                        image[x][y]=c;
                        
                        dfs(x,y,c,image);
                    }
                }
                
            }
        }
    }
};