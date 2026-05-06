// 0877. Stone Game
// Difficulty : Medium
// Tags       : array, math, dynamic-programming, game-theory
// Solved on  : 2019-10-18
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/stone-game/

class Solution {
public:
    int d[510][510];
    vector<int> v;
    bool stoneGame(vector<int>& piles) {
        memset(d,-1,sizeof(d));
        int x=f(0,piles.size()-1,piles);
        int y=0;
        for(int i=0;i<v.size();i++){
            y+=piles[v[i]];
        }
        if(x>y){
            return true;
        }
        return false;
    }
    int f(int i,int j,vector<int>& piles){
        
        if(i==j){
            return 0;
        }
        if(d[i][j]!=-1){
            return d[i][j];
        }
        if(piles[i]>piles[j]){
            d[i][j]=f(i+1,j,piles)+piles[i];
            v.push_back(j);
        }else{
             d[i][j]=f(i,j-1,piles)+piles[j];
            v.push_back(i);
        }
        return d[i][j];
    }
};