// 0014. Longest Common Prefix
// Difficulty : Easy
// Tags       : array, string, trie
// Solved on  : 2023-01-07
// LeetCode   : https://leetcode.com/problems/longest-common-prefix/

/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    var min_length = 1000;
    for(var i = 0; i < strs.length ;i++)
    {
        min_length=Math.min(min_length,strs[i].length);
    }
    var result = strs[0].substring(0,min_length);
    for(var i = 0; i < strs.length ;i++)
    {
        for(var j = 0 ; j < min_length; j++ )
        {
            if(strs[0][j] != strs[i][j])
            {
                //console.log(result.length+'=>'+j);
                if(result.length > j )
                {
                    var temp = strs[0].substring(0,j);
                    if(temp.length < result.length) result = temp;
                    break;
                }
                //console.log(i+','+j+'=>'+strs[0][j]+','+strs[i][j]);
                // strs[0].substring(0,j);
            }
        }
    }
    return result;
};