// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2022-06-16
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/valid-parentheses/

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack=[];
    for( let i = 0 ; i < s.length ; i++ )
    {
        if( s[i]==')' ||  s[i]=='}' || s[i]==']' )
        {
            if( stack === undefined || stack.length == 0 ) return false;
            let char=stack.pop();
            if((s[i] == ')' && char == '(' ) || (s[i] == '}' && char == '{') || (s[i] == ']' && char == '['))
            {
                
            }
            
            else{
                return false;
            }
        }
        else
        {
            stack.push(s[i]);   
        }
    }
    if(stack === undefined || stack.length == 0) return true ;
    else return false;
};