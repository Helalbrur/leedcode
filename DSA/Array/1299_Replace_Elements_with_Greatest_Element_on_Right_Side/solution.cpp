// 1299. Replace Elements with Greatest Element on Right Side
// Difficulty : Easy
// Tags       : array
// Solved on  : 2019-12-28
// LeetCode   : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx=-1;
        int sz=arr.size();
        for(int i=sz-1;i>=0;i--){
            int t=arr[i];
            arr[i]=mx;
            mx=max(t,mx);
        }
        return arr;
        
    }
};