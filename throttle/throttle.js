/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
const throttle = (fn, t) => {   
    let prev = -1;
    let time = null;
    return (...args) => {
        var currTime = Date.now();
        if(currTime - prev >=t){
            fn(...args);
            prev = currTime;
        }else{
            clearTimeout(time);
            time= setTimeout(()=>{
                fn(...args);
                time = null;
                prev += t;
            }, prev+t-currTime);
        }
    }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */