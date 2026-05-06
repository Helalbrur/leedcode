// 0004. Median of Two Sorted Arrays
// Difficulty : Hard
// Tags       : array, binary-search, divide-and-conquer
// Solved on  : 2018-11-20
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size(),s2=nums2.size();
        int s=s1+s2;
        if(s%2==0){
            int m=s/2;
            int i=0,j=0,n=1;
            double num1,num2,temp;
            while(i<s1 && j<s2 && n<=m+1){
                
                if(nums1[i]>nums2[j]){
                    temp=nums2[j];
                    j++;
                }else{
                    temp=nums1[i];
                    i++;
                }
                if(n==m){
                    num1=temp;
                }
                if(n==m+1){
                    num2=temp;
                }
                n++;
            }
            while(i<s1  && n<=m+1){
                
                temp=nums1[i];
                i++;
                
                if(n==m){
                   num1=temp;
                }
                if(n==m+1){
                    num2=temp;
                }
                n++;
            }
            while(j<s2  && n<=m+1){
                
                temp=nums2[j];
                j++;
                
                if(n==m){
                    num1=temp;
                }
                if(n==m+1){
                    num2=temp;
                }
                n++;
            }
            return (num1+num2)/2;
            
        }else{
            int m=s/2+1;
            int i=0,j=0,n=1;
            while(i<s1 && j<s2 && n<=m){
                double num;
                if(nums1[i]>nums2[j]){
                    num=nums2[j];
                    j++;
                }else{
                    num=nums1[i];
                    i++;
                }
                if(n==m){
                    return num;
                }
                n++;
            }
            while(i<s1  && n<=m){
                double num;
                num=nums1[i];
                i++;
                
                if(n==m){
                    return num;
                }
                n++;
            }
            while(j<s2  && n<=m){
                double num;
                num=nums2[j];
                j++;
                
                if(n==m){
                    return num;
                }
                n++;
            }
        }
        
    }
};