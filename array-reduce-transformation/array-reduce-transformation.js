/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
let reduce = (nums, fn, init) => {
    nums.forEach(num => {
        init = fn(init, num)
    })
    return init;
};