/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let tillNow = Number.POSITIVE_INFINITY, ans = 0;
    for(let i=0;i<prices.length;i++){
        tillNow = Math.min(tillNow, prices[i]);
        ans = Math.max(ans, prices[i]-tillNow);
    }
    return ans
};