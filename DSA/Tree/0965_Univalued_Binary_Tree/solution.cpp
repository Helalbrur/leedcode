// 0965. Univalued Binary Tree
// Difficulty : Easy
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2019-07-22
// LeetCode   : https://leetcode.com/problems/univalued-binary-tree/

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
    map<int,int> mp;
    bool isUnivalTree(TreeNode* root) {
        
         isUnT( root);
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();++it){
           cnt++;
        }
        if(cnt==1){
            return true;
        }
        return false;
       
    }
    
    void isUnT(TreeNode* root){
        
        if(root==NULL){
            return ;
        }
        
        
            mp[root->val]++;
           
            isUnT(root->left) ;
            isUnT(root->right);
        
        
        
       
    }
};