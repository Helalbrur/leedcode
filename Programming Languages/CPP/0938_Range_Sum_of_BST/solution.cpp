// 0938. Range Sum of BST
// Difficulty : Easy
// Tags       : tree, depth-first-search, binary-search-tree, binary-tree
// Solved on  : 2019-07-21
// Attempt    : #1
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
    set<int> s;
    int rangeSumBST(TreeNode* root, int L, int R) {
       s.clear();
        rsum(root,L,R);
        int sum=0;
        for(auto it=s.begin();it!=s.end();++it){
            sum+=*it;
        }
        return sum;
    }
    
    void rsum(TreeNode* root, int L, int R){
        TreeNode* head=root;
       
        if(root==NULL)
            return;
            
        if(root->val>=L && root->val<=R){
            s.insert(root->val);
        }
             //cout<<root->val<<endl;
            rsum(root->left,L,R);
            rsum(root->right,L,R);

       
    }
};