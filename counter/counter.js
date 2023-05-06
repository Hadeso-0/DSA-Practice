/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var cnt = -1;
    return () => {
        cnt+=1
        return (n+cnt) 
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */