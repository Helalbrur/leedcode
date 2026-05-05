// 1196. How Many Apples Can You Put into the Basket
// Difficulty : Easy
// Tags       : array, greedy, sorting
// Solved on  : 2019-09-21
// LeetCode   : https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long int sum=0;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if((arr[i]+sum)<5000){
                sum+=arr[i];
                cnt++;
            }
        }
        return cnt;
    }
};