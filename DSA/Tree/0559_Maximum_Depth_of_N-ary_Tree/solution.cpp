// 0559. Maximum Depth of N-ary Tree
// Difficulty : Easy
// Tags       : tree, depth-first-search, breadth-first-search
// Solved on  : 2019-07-27
// LeetCode   : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
   
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
        int mx=1;
        for(int i=0;i< root->children.size();i++){
            mx=max(mx,maxDepth(root->children[i])+1);
        }
        return mx;
    }
    
};