// 0104. Maximum Depth of Binary Tree
// Difficulty : Easy
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2022-06-26
// LeetCode   : https://leetcode.com/problems/maximum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    return mh(root);
};

function mh(root)
{
    if(root===undefined || root === null) return 0;
    return Math.max(mh(root.left)+1,mh(root.right)+1);
}