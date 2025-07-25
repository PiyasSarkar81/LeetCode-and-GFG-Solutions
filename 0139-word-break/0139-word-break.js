/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    const dp = new Array(s.length).fill(-1)
    const st = new Set(wordDict)

    function solve(l){
        if(l === s.length) return true
        if(dp[l] !== -1) return dp[l]
        for(let r = l+1;r<=s.length;r++) {
            let subStr = s.substring(l,r);
            if(st.has(subStr) && solve(r)){
                dp[l] = true
                return true
            }
        }
        dp[l] = false
        return false
    }

    return solve(0)
};