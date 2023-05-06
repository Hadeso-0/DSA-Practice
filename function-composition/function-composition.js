/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = (functions) => {
	functions = functions.slice().reverse()
    return (x) => {
        functions.forEach((fn) => {
            x = fn(x)
        })
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */