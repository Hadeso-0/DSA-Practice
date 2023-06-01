/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    if(n==0) return arr

    let ans = []
    arr.forEach(el => {
        if(Array.isArray(el)){
            let flatte = flat(el, n-1)
            flatte.forEach( x => ans.push(x))
        }
        else ans.push(el)
    })
    return ans
};