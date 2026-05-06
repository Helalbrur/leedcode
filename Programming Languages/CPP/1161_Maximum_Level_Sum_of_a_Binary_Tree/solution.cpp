// 1161. Maximum Level Sum of a Binary Tree
// Difficulty : Medium
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2019-08-18
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int mx=INT_MIN;
    int dp[100000];
    int l=0;
    int maxLevelSum(TreeNode* root) {
         mx=INT_MIN;
        l=0;
        memset(dp,0,sizeof(dp));
        dfs(root,1);  
       for(int i=0;i<100000;i++){
           if(dp[i]>mx){
               mx=dp[i];
               l=i;
           }
       }
        return l;
    }
   
    void dfs(TreeNode* root,int level){
        if(root==NULL)
            return;
        dp[level]+=root->val;
      
        dfs(root->left,level+1);
        dfs(root->right,level+1);
        
    }
};