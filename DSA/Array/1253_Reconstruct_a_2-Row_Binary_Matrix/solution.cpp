// 1253. Reconstruct a 2-Row Binary Matrix
// Difficulty : Medium
// Tags       : array, greedy, matrix
// Solved on  : 2019-11-10
// LeetCode   : https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum=0;
        vector<vector<int>> v;
        for(int i=0;i<colsum.size();i++){
            sum+=colsum[i];
        }
        if(sum!=upper+lower){
            return v;
        }
        vector<int> a,b;
        
        for(int i=0;i<colsum.size();i++){
            if(upper>=colsum[i]){
                a.push_back(colsum[i]);
                b.push_back(0);
                upper-=colsum[i];
            }else if(upper>0){
                a.push_back(upper);
                b.push_back(colsum[i]-upper);
                lower-=colsum[i]-upper;
                upper=0;
            }else{
                a.push_back(0);
                b.push_back(colsum[i]);
                lower-=colsum[i];
            }
        }
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};