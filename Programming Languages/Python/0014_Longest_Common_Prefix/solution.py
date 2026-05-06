# 0014. Longest Common Prefix
# Difficulty : Easy
# Tags       : array, string, trie
# Solved on  : 2026-04-21
# Attempt    : #1
# LeetCode   : https://leetcode.com/problems/longest-common-prefix/

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        if n == 1:
            return strs[0]
        elif n == 0:
            return ""
        mn = 201
        pos = 0
        for i,s in enumerate(strs):
            if len(s) < mn :
                mn = len(s)
                pos = i
        if mn == 0:
            return ""
        for i in range(mn):
            for j in range(n):
                if strs[pos][i] != strs[j][i]:
                    return strs[pos][:i];
        return strs[pos][:(mn+1)]
