# 0020. Valid Parentheses
# Difficulty : Easy
# Tags       : string, stack
# Solved on  : 2026-04-23
# LeetCode   : https://leetcode.com/problems/valid-parentheses/

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        maping = { ')' : '(' ,'}' : '{' , ']' : '['}
        for c in s:
            if c in maping:
                if not stack or stack.pop() != maping[c]:
                    return False
            else:
                stack.append(c)
        return not stack     
        

                
