// 0104. Maximum Depth of Binary Tree
// Difficulty : Easy
// Tags       : tree, depth-first-search, breadth-first-search, binary-tree
// Solved on  : 2022-07-06
// LeetCode   : https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    function maxDepth($root) {
        if( $root == null ) return 0;
        return maxD($root);
    }
}

function maxD($root)
{
    if($root == null) return 0;
    return max(maxD($root->left)+1,maxD($root->right)+1);
}