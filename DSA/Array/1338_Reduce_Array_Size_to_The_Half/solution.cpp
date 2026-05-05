// 1338. Reduce Array Size to The Half
// Difficulty : Medium
// Tags       : array, hash-table, greedy, sorting, heap-priority-queue
// Solved on  : 2020-02-02
// LeetCode   : https://leetcode.com/problems/reduce-array-size-to-the-half/

int a[100010];
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        memset(a,0,sizeof(a));
        for(int i=0;i<arr.size();i++){
            a[arr[i]]++;
        }
        vector< pair<int,int> > v;
        for(int i=0;i<=100000;i++){
            if(a[i]>0){
                v.push_back({a[i],i});
            }
        }
        sort(v.begin(),v.end());
        int c=0;
        for(int i=v.size()-1;i>=0;i--){
            c+=v[i].first;
            if(c>=((arr.size()+1)/2)) return v.size()-i;
        }
        return arr.size();
    }
};