// 0111. Minimum Depth of Binary Tree
// Difficulty : Easy
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2022-07-06
// LeetCode   : https://leetcode.com/problems/minimum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($val = 0, $left = null, $right = null) {
 *         $this->val = $val;
 *         $this->left = $left;
 *         $this->right = $right;
 *     }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function minDepth($root) {
        if($root === null) return 0;
        return minD($root);
    }
    
    
}

function minD($root)
{
    if($root === null) return 100000;
    if($root->left === null && $root->right === null) return 1;
    return min(minD($root->left)+1,minD($root->right)+1);
}