// 1380. Lucky Numbers in a Matrix
// Difficulty : Easy
// Tags       : array, matrix
// Solved on  : 2020-03-15
// LeetCode   : https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int mx=INT_MIN;
        pair<int,int> p;
        pair<int,int> q;
        for(int i=0;i<matrix.size();i++){
            int mn=INT_MAX;
            
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]<mn){
                    mn=matrix[i][j];   
                    p.first=i;
                    p.second=j;
                }
                
            }
            if(mn>mx){
                mx=mn;
                q.first=p.first;
                q.second=p.second;
            }
           
        }
        bool ok=true;
        for(int i=0;i<matrix[q.first].size();i++){
            if(matrix[q.first][i]<mx){
                ok=false;
            }
        }
        int j=0;
        for(int i=0;i<matrix.size();i++){
            if(mx<matrix[i][q.second]){
                ok=false;
            }
        }
        vector<int> v;
        if(ok)
            v.push_back(mx);
        return v;
    }
};