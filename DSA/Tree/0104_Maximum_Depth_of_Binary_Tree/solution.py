# 0104. Maximum Depth of Binary Tree
# Difficulty : Easy
# Tags       : tree, depth-first-search, breadth-first-search, binary-tree
# Solved on  : 2022-07-06
# LeetCode   : https://leetcode.com/problems/maximum-depth-of-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        return maxD(self,root)
def maxD(self,root: Optional[TreeNode]) -> int:
    if root == None:
        return -100000
    if root.left == None and root.right == None:
        return 1
    return max(maxD(self,root.left)+1,maxD(self,root.right)+1);
        