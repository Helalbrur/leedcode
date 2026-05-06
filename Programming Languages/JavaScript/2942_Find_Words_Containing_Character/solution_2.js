// 2942. Find Words Containing Character
// Difficulty : Easy
// Tags       : array, string
// Solved on  : 2025-10-20
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/find-words-containing-character/

/**
 * @param {string[]} words
 * @param {character} x
 * @return {number[]}
 */
var findWordsContaining = function(words, x) {
    return words.reduce((res,word,i)=>{
        if(word.includes(x)) res.push(i);
        return res;
    },[]);
};