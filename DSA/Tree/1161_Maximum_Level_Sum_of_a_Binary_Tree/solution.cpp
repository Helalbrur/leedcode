// 1161. Maximum Level Sum of a Binary Tree
// Difficulty : Medium
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2020-01-19
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
    int dp[100010];
    int mxLabel=1;
    int maxLevelSum(TreeNode* root) {
        memset(dp,0,sizeof(dp));
        dfs(root,1);
        int mx=INT_MIN;
        int level=0;
        for(int i=1;i<=mxLabel;i++){
            if(dp[i]>mx){
                mx=dp[i];
                level=i;
            }
            mx=max(mx,dp[i]);
            cout<<i<<" "<<dp[i]<<endl;
        }
        return level;
    }
    
    void dfs(TreeNode* root,int level){
        if(root==NULL)
            return;
        dp[level]+=root->val;
        mxLabel=max(mxLabel,level);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
};