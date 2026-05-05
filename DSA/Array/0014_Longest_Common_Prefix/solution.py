# 0014. Longest Common Prefix
# Difficulty : Easy
# Tags       : array, string, trie
# Solved on  : 2026-04-21
# LeetCode   : https://leetcode.com/problems/longest-common-prefix/

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        for i,s in enumerate(zip(*strs)):
            if len(set(s)) > 1:
                return strs[0][:i]
        return min(strs,key=len)