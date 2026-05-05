// 0111. Minimum Depth of Binary Tree
// Difficulty : Easy
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2022-07-06
// LeetCode   : https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
var minDepth = function(root) {
    if(root ===undefined || root === null ) return 0;
    return minD(root);
};

function minD(root)
{
    if(root ===undefined || root === null) return 100000;
    if((root.left ===undefined || root.left === null) && (root.right ===undefined || root.right === null))  return 1; 
    return Math.min(minD(root.left)+1,minD(root.right)+1);
}