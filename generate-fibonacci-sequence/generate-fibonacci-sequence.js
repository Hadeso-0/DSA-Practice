/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let x1 = 0
    let x2 = 1
    while(true){
        yield x1
        let tmp = x1 + x2
        x1 = x2
        x2 = tmp
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */