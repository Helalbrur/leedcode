// 1302. Deepest Leaves Sum
// Difficulty : Medium
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2019-12-28
// LeetCode   : https://leetcode.com/problems/deepest-leaves-sum/

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
    vector<int> v[100000];
    int mx=0;
    int deepestLeavesSum(TreeNode* root) {
        TreeNode* temp=root;
       
        f(root,0);
        long long s=0;
        for(int i=0;i<v[mx].size();i++){
            s+=v[mx][i];
        }
        return s;
    }
    void f(TreeNode* root,int c){
        if(root==NULL)
            return;
        f(root->left,c+1);
        f(root->right,c+1);
        v[c].push_back(root->val);
        mx=max(mx,c);
    }
};