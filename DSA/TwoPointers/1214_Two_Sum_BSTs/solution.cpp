// 1214. Two Sum BSTs
// Difficulty : Medium
// Tags       : two-pointers, binary-search, stack, tree, depth-first-search, binary-search-tree, binary-tree
// Solved on  : 2019-10-05
// LeetCode   : https://leetcode.com/problems/two-sum-bsts/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        traverse1(root1);
        traverse2(root2);
        
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
               if(target==a[i]+b[j]){
                   return true;
               }
            }
        }
        return false;
    }
    void traverse1(TreeNode* root1){
       
        if(root1==NULL)
            return;
        if(root1->val){
             a.push_back(root1->val);
        }
      
        //cout<<a<<endl;
        traverse1(root1->left);
        traverse1(root1->right);
        
    }
    void traverse2(TreeNode* root2){
        
        if(root2==NULL)
            return;
        if(root2->val){
             b.push_back(root2->val);
        }
       
        //cout<<b<<endl;
        traverse2(root2->left);
        traverse2(root2->right);
    }
};