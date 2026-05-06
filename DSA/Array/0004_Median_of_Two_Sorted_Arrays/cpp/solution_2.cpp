// 0004. Median of Two Sorted Arrays
// Difficulty : Hard
// Tags       : array, binary-search, divide-and-conquer
// Solved on  : 2019-08-05
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        int s=v.size();
        if(s%2==0){
          return (v[s/2]+v[s/2-1])/2.0;
        }else{
            return v[s/2];
        }
        
    }
};