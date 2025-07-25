/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    let ans = 1
    const arr = []
    arr.push(nums[0])

    function lowerBound(nums, target){
        let l = 0, r = nums.length
        while(l<r){
            let m = l +Math.floor((r-l)/2)
            if(nums[m] < target){
                l = m+1;
            }
            else{
                r = m;
            }
        }
        return l;
    }
    for(let i=1;i<nums.length;i++){
        if(nums[i] > arr[arr.length-1]){
            ans++
            arr.push(nums[i])
        }
        else{
            const idx = lowerBound(arr, nums[i])
            arr[idx] = nums[i]
        }
    }
    return ans
};