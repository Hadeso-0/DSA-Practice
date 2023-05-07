/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
let createCounter = (init) => {
    val = init
    resetVal = val
    return {
        increment : () => val +=1,
        decrement : () => val -=1,
        reset : () => val = resetVal
    }
}
/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */