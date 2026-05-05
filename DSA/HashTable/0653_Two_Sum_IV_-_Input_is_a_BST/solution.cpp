// 0653. Two Sum IV - Input is a BST
// Difficulty : Easy
// Tags       : hash-table, two-pointers, tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree
// Solved on  : 2019-07-21
// LeetCode   : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    set<int> s;
    bool findTarget(TreeNode* root, int k) {
        s.clear();
        return rfind(root,k);
        
        
    }
    
    bool rfind(TreeNode* root, int k){
        if(root==NULL){
            return false;
        }
        
        if(s.count(k-root->val)){
            return true;
        }
        s.insert(root->val);
        return (rfind(root->left,k)||rfind(root->right,k));
    }
};