/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    let ans = []
    let ind = 0

    while(ind < arr.length) {
        ans.push(arr.slice(ind, ind + size))
        ind += size
    }

    return ans
};