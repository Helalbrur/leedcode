// 1200. Minimum Absolute Difference
// Difficulty : Easy
// Tags       : array, sorting
// Solved on  : 2019-09-22
// LeetCode   : https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int s=arr.size();
        int mn=INT_MAX;
        for(int i=1;i<s;i++){
            mn=min(mn,arr[i]-arr[i-1]);
        }
        //cout<<mn<<endl;
        vector<vector<int>> v;
        for(int i=1;i<s;i++){
            if((arr[i]-arr[i-1])==mn){
                vector<int> a;
                a.push_back(arr[i-1]);
                a.push_back(arr[i]);
                v.push_back(a);
            }
            
        }
        return v;
    }
};