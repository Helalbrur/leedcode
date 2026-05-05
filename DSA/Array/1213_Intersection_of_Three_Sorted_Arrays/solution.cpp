// 1213. Intersection of Three Sorted Arrays
// Difficulty : Easy
// Tags       : array, hash-table, binary-search, counting
// Solved on  : 2019-10-05
// LeetCode   : https://leetcode.com/problems/intersection-of-three-sorted-arrays/

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        
        vector<int> v;
       
        int vis[2010];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<arr1.size();i++){
            
           vis[arr1[i]]=1;
           
        }
        for(int i=0;i<arr2.size();i++){
            
            if(vis[arr2[i]]==1){
                vis[arr2[i]]=2;
            }
        }
        for(int i=0;i<arr3.size();i++){
            
           if(vis[arr3[i]]==2){
                vis[arr3[i]]=3;
            }
        }
        for(int i=1;i<=2000;i++){
            
            if(vis[i]==3){
                v.push_back(i);
            }
        }
        return v;
    }
};