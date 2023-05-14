/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    let nums = []
    return function curried(...args) {
        nums = [...nums, ...args];
        if(fn.length === nums.length) {
            const ans = fn(...nums);
            nums = []
            return ans;
        } else {
            return curried;
        }
    };

    // recursive

    // return function curried(...args) {
    //     if(fn.length === args.length) {
    //         return fn(...args);
    //     } else {
    //         return function(...newArgs) {
    //             return curried(...args, ...newArgs);
    //         }
    //     }
    // }; 
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */