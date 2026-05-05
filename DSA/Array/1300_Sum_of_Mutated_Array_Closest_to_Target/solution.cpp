// 1300. Sum of Mutated Array Closest to Target
// Difficulty : Medium
// Tags       : array, binary-search, sorting
// Solved on  : 2019-12-28
// LeetCode   : https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int s=target/arr.size();
        int st;
        if(s>=10000){
            st=s-10000;
        }
        else if(s>=1000){
            st=s-1000;
        }else if(s>=100){
            st=s-100;
        }else if(s>=50){
            st=s-50;
        }else if(s>=10){
            st=s-10;
        }
        else{
            st=s;
        }
        cout<<s<<" "<<st<<endl;
        long long d=INT_MAX,p=0;
        for(int i=st;i<s+10050;i++){
            long long s=0;
            for(int j=0;j<arr.size();j++){
                if(arr[j]>i){
                    s+=i;
                }else{
                    s+=arr[j];
                }
            }
            if(abs(target-s)<d){
                d=abs(target-s);
                p=i;
            }
           
        }
        return p;
    }
};