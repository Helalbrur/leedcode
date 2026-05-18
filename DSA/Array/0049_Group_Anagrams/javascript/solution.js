// 0049. Group Anagrams
// Difficulty : Medium
// Tags       : array, hash-table, string, sorting
// Solved on  : 2026-05-18
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/group-anagrams/

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var len = 'z'.codePointAt(0) - 'a'.codePointAt(0) + 1;
    var charCount = Array.from({length:strs.length},()=>Array(len).fill(0));
    strs.forEach((str,i)=>{
        for(let x of Array.from(str)){
            let ascii_value = x.codePointAt(0) - 'a'.codePointAt(0);
            charCount[i][ascii_value]++;
        }
    });
    obj = {};
    charCount.forEach((y,i)=>{
        if(!obj[y])
        {
            obj[y] =[]
        }
        obj[y].push(strs[i]);
    });
    var res = [];
    for(const [key,val] of Object.entries(obj)){
        res.push(val);
    }
    return res;
    
};