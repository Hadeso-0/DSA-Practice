/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
let promisePool = async(functions, n) => {
    const evalNex = () => functions[n++]?.().then(evalNex);
    return Promise.all(functions.slice(0, n).map(f => f().then(evalNex)));
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */