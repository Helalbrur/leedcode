// 2665. Counter II
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/counter-ii/

type Counter = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): Counter {
    const first : number = init;
    return {
        increment: () => ++init,
         decrement: () => --init,
         reset: () => init = first 
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */