/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    const n = s.length
    const dp = new Array(n).fill(-1)

    function solve(idx){
        if(idx == s.length) return 1
        if(dp[idx] != -1) return dp[idx]
        let one = 0, two = 0
        if(s[idx] == "0") return 0
        else one = solve(idx+1)
        if(idx+1 != s.length && s.substr(idx,2) <= "26") two = solve(idx+2)
        return dp[idx] = one + two
    }

    return solve(0)
};