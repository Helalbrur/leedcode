// 2942. Find Words Containing Character
// Difficulty : Easy
// Tags       : array, string
// Solved on  : 2025-10-20
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/find-words-containing-character/

/**
 * @param {string[]} words
 * @param {character} x
 * @return {number[]}
 */
var findWordsContaining = function(words, x) {
    var res = [];
    for(var i = 0; i < words.length; i++)
    {
        for(var j= 0; j<words[i].length;j++)
        {
            if(x == words[i][j]){
                res.push(i);
                break;
            }
        }
    }
    return res;
};