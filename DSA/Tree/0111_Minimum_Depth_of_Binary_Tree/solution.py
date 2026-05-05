# 0111. Minimum Depth of Binary Tree
# Difficulty : Easy
# Tags       : tree, depth-first-search, breadth-first-search, binary-tree
# Solved on  : 2022-07-06
# LeetCode   : https://leetcode.com/problems/minimum-depth-of-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        return minD(self,root);
def minD(self,root: Optional[TreeNode]) -> int:
    if root == None:
        return 100000
    if root.left == None and root.right == None:
        return 1
    return min(minD(self,root.left)+1,minD(self,root.right)+1)
        