/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    
    // return nums.reduce(fn,init);

    let ans = init;

    nums.forEach((n) => {
        ans = fn(ans, n);
    });

    // for(const n of nums) {
    //     ans = fn(ans, n);
    // }

    return ans;
};