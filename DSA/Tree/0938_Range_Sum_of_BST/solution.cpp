// 0938. Range Sum of BST
// Difficulty : Easy
// Tags       : tree, depth-first-search, binary-search-tree, binary-tree
// Solved on  : 2019-08-09
// LeetCode   : https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        if(root==NULL){
            return 0;
        }
        if(root->val>=L && root->val<=R){
            sum+=root->val;
        }
        return sum+=rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R);
    }
};