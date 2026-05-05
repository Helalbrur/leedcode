// 3110. Score of a String
// Difficulty : Easy
// Tags       : string
// Solved on  : 2025-10-20
// LeetCode   : https://leetcode.com/problems/score-of-a-string/

/**
 * @param {string} s
 * @return {number}
 */
var scoreOfString = function(s) {
    var score = 0;
    var i = 0;
    for(i = 0; i < s.length -1 ; i++)
    {
        score += Math.abs(s.charCodeAt(i) - s.charCodeAt(i+1));
    }
    return score;
};