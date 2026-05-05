// 2942. Find Words Containing Character
// Difficulty : Easy
// Tags       : array, string
// Solved on  : 2025-10-20
// LeetCode   : https://leetcode.com/problems/find-words-containing-character/

/**
 * @param {string[]} words
 * @param {character} x
 * @return {number[]}
 */
var findWordsContaining = function(words, x) {
    return words.map((word,i)=>word.includes(x) ? i : -1).filter(i=> i >=0);
};