// 2704. To Be Or Not To Be
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/to-be-or-not-to-be/

type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    const throwError = (errorStr) =>{throw new Error(errorStr)}
    return {
         toBe : (val2) => val2 === val || throwError("Not Equal"),
         notToBe : (val2) => val2 !== val || throwError("Equal")
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */