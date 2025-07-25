/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    const n = coins.length
    const dp = Array.from({length: n} , () => Array(amount+1).fill(-1))

    function helper(idx, amount){
        if(idx === 0){
            if(amount % coins[0] === 0) return amount/coins[0]
            return Number.MAX_SAFE_INTEGER;
        }
        if (dp[idx][amount] !== -1) return dp[idx][amount];
        const notTake = helper(idx-1,amount)
        let take = Number.MAX_SAFE_INTEGER
        if(coins[idx] <= amount) take = 1+ helper(idx,amount-coins[idx])

        return dp[idx][amount] = Math.min(take, notTake)
    }

    const ans = helper(n-1, amount)
    return ans >= Number.MAX_SAFE_INTEGER ? -1 : ans
};