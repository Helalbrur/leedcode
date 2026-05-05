// 1331. Rank Transform of an Array
// Difficulty : Easy
// Tags       : array, hash-table, sorting
// Solved on  : 2020-01-25
// LeetCode   : https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0){
            vector<int> res;
            return res;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int n=arr.size();
        vector<int> vec(n,0);
        int cnt=1;
        int mx=v[0].first;
        for(int i=0;i<n;i++){
            if(v[i].first>mx){
                mx=v[i].first;
                cnt++;
                vec[v[i].second]=cnt;
            }else{
                vec[v[i].second]=cnt;
            }
        }
        return vec;
        
    }
};