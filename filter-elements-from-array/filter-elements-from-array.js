/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
let filter = (arr, fn) => arr.filter((n,i) => fn(n,i))