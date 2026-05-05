// 1198. Find Smallest Common Element in All Rows
// Difficulty : Medium
// Tags       : array, hash-table, binary-search, matrix, counting
// Solved on  : 2019-09-21
// LeetCode   : https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> m;
        for(int i=0;i<mat.size();i++){
            map<int,int> x;
            for(int j=0;j<mat[i].size();j++){
                x[mat[i][j]]++;
                
            }
            for(auto it=x.begin();it!=x.end();++it){
                m[it->first]++;
            }
        }
        int s=mat.size();
        int n=1000000;
        for(auto i=m.begin();i!=m.end();++i){
            if(i->second>=s){
                n=min(n,i->first);
            }
            
        }
        if(n==1000000){
            return -1;
        }
        return n;
        
    }
};