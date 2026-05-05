// 1376. Time Needed to Inform All Employees
// Difficulty : Medium
// Tags       : tree, depth-first-search, breadth-first-search
// Solved on  : 2020-03-15
// LeetCode   : https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    vector<int> edge[100010];
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        
        for(int i=0;i<manager.size();i++){
           if(manager[i]>=0){
               edge[manager[i]].push_back(i);
               
           }
        }
       // cout<<edge[headID].size()<<endl;
      
        return dfs(headID,informTime);
    }
    int dfs(int headID,vector<int>& inf){
        int s=0;
        for(int i=0;i<edge[headID].size();i++){
            s=max(s,dfs(edge[headID][i],inf));
            
        }
        return inf[headID]+s;
    }
};