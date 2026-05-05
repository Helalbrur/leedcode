// 2620. Counter
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/counter/

function createCounter(n: number): () => number {
    
    return function() {
        return n++;
    }
}


/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */