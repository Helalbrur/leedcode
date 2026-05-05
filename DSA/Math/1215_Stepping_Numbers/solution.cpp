// 1215. Stepping Numbers
// Difficulty : Medium
// Tags       : math, backtracking, breadth-first-search
// Solved on  : 2019-10-06
// LeetCode   : https://leetcode.com/problems/stepping-numbers/

class Solution {
public:
    vector<int> v;
    void dfs(long long int low,long long int high,long long int stepNumber){
        if(high>=stepNumber && stepNumber>=low){
            v.push_back(stepNumber);
        }
        if(stepNumber==0 || stepNumber>high){
            return;
        }
        int lastDigit=stepNumber%10;
        long long int stepNumberA=stepNumber*10+(lastDigit+1);
        long long int stepNumberB=stepNumber*10+(lastDigit-1);
        if(lastDigit==0){
            dfs(low,high,stepNumberA);
        }
       else if(lastDigit==9){
            dfs(low,high,stepNumberB);
        }else{
           dfs(low,high,stepNumberA);
           dfs(low,high,stepNumberB);
       }
    }
    vector<int> countSteppingNumbers(int low, int high) {

       for(int i=0;i<=9;i++){
           dfs(low,high,i);
       }
        
       sort(v.begin(),v.end());
        return v;
        
    }
};