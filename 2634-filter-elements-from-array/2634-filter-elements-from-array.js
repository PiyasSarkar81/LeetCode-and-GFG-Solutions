/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    // declaretive program
    // return arr.filter(fn);


    // imparetive programing
    // const ans = []

    // for(const i in arr){
    //     if(fn(arr[i],Number(i))) {
    //         ans.push(arr[i]);
    //     }
    // }
    // return ans;


    // better solution 
     const ans = []

    for(let i = 0;i < arr.length; i++){
        if(fn(arr[i], i)) {
            ans.push(arr[i]);
        }
    }
    return ans;

};