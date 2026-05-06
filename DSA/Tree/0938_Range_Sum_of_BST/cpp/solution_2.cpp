// 0938. Range Sum of BST
// Difficulty : Easy
// Tags       : tree, depth-first-search, binary-search-tree, binary-tree
// Solved on  : 2019-07-21
// Attempt    : #2
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
       
        
        return rsum(root,L,R);
        
       
        
       
    }
    
    int rsum(TreeNode* root, int L, int R){
        
        int sum=0;
        if(root==NULL)
            return sum;
            
        if(root->val>=L && root->val<=R){
            //s.insert(root->val);
            sum+=root->val;
        }
             //cout<<root->val<<endl;
            return sum+=rsum(root->left,L,R)+ rsum(root->right,L,R);

       
    }
};