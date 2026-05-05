// 1228. Missing Number In Arithmetic Progression
// Difficulty : Easy
// Tags       : array, math
// Solved on  : 2019-10-19
// LeetCode   : https://leetcode.com/problems/missing-number-in-arithmetic-progression/

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        
        int mx[5][5];
        memset(mx,0,sizeof(mx));
        for(int i=1;i<arr.size();i++){
            int a=abs(arr[i]-arr[i-1]);
            if(a>=mx[0][0]){
                //cout<<a<<" "<<i<<endl;
                 mx[1][0]=mx[0][0];
                 mx[1][1]=mx[0][1];
                
                mx[0][0]=a;
                mx[0][1]=i;
             
            }else if(a>=mx[1][0]){
                mx[1][0]=a;
                mx[1][1]=i;
            }
        }
       // cout<<mx[0][1]<<" "<<arr[mx[0][1]-1]<<" "<<mx[1][0]<<endl;
        if(arr[0]>arr[1]){
            return arr[mx[0][1]-1]-mx[1][0];
        }
        return arr[mx[0][1]-1]+mx[1][0];
        
    }
};