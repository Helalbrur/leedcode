# 2942. Find Words Containing Character
# Difficulty : Easy
# Tags       : array, string
# Solved on  : 2025-10-20
# LeetCode   : https://leetcode.com/problems/find-words-containing-character/

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        return [i for i , word in enumerate(words) if x in word]