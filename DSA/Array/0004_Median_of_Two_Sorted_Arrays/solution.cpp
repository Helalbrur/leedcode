// 0004. Median of Two Sorted Arrays
// Difficulty : Hard
// Tags       : array, binary-search, divide-and-conquer
// Solved on  : 2021-02-12
// LeetCode   : https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=(nums1.size()+nums2.size())/2;
        int i=0,j=0;
        int a[n+2];
        memset(a,0,sizeof(a));
        while(i<nums1.size() && j<nums2.size() && i+j<=n)
        {
            if(nums1[i]<nums2[j])
            {
                a[i+j]=nums1[i];
                i++;
            }
            else{
                a[i+j]=nums2[j];
                j++;
            }
        }
        while(i<nums1.size() && i+j<=n)
        {
            a[i+j]=nums1[i];
            i++;
        }
        while( j<nums2.size() && i+j<=n)
        {
            a[i+j]=nums2[j];
            j++;
        }
        if((nums1.size()+nums2.size())%2==0)
        {
            return (a[n]+a[n-1])/2.0;
        }
        return a[n];
    }
};