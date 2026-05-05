// 0102. Binary Tree Level Order Traversal
// Difficulty : Medium
// Tags       : tree, breadth-first-search, binary-tree
// Solved on  : 2020-02-01
// LeetCode   : https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<int> v[1000];
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        vector<vector<int>> c;
        for(int i=0;i<1000;i++){
            vector<int> x;
            for(int j=0;j<v[i].size();j++){
                x.push_back(v[i][j]);
            }
            if(x.size())
                c.push_back(x);
        }
        return c;
    }
   void dfs(TreeNode* root,int level){
        if(root==NULL) return ;
        v[level].push_back(root->val);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
};