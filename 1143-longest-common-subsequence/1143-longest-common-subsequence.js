/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2) {
    const n1 = text1.length, n2 = text2.length
    const dp = Array.from({length: n1+1}, () => Array(n2+1).fill(0))
    
    for(let i=0;i<n1;i++){
        for(let j=0;j<n2;j++){
            if(text1[i] === text2[j]){
                dp[i+1][j+1] = 1+ dp[i][j]
            }
            else{
                dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1])
            }
        }
    }

    return dp[n1][n2]
};