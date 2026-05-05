// 0111. Minimum Depth of Binary Tree
// Difficulty : Easy
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2020-02-01
// LeetCode   : https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return depth(root);
    }
    int depth(TreeNode* root){
        if(root==NULL) return 100000;
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        
        return min(depth(root->left)+1,depth(root->right)+1);
    }
};