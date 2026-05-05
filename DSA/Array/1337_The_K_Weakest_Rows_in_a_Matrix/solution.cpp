// 1337. The K Weakest Rows in a Matrix
// Difficulty : Easy
// Tags       : array, binary-search, sorting, heap-priority-queue, matrix
// Solved on  : 2020-02-02
// LeetCode   : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    c++;
                }
            }
            v.push_back({c,i});
        }
        sort(v.begin(),v.end());
        vector<int> res;
        int sz=v.size();
        for(int i=0;i<min(sz,k);i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};