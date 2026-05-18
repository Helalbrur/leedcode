// 0049. Group Anagrams
// Difficulty : Medium
// Tags       : array, hash-table, string, sorting
// Solved on  : 2026-05-18
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/group-anagrams/

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var map = new Map();
    strs.forEach((str)=>{
        const count = new Array(26).fill(0);
        for(const x of str){
            const ascii = x.codePointAt(0) -'a'.codePointAt(0);
            count[ascii]++;
        }
        const key = count.join("#"); // with character counting array makes a unique string key
        if(!map.has(key)){
            map.set(key,[]);
        }
        map.get(key).push(str);
    });
    return [...map.values()]
    
};