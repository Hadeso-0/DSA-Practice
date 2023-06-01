class EventEmitter {
    callbacks = [];
    subscribe(event, cb) {
        this.callbacks[event] = this.callbacks[event] || [];
        this.callbacks[event].push(cb);

        return {
            unsubscribe: () => {
                if (this.callbacks[event].length > 1)
                    this.callbacks[event].pop();
                else
                    delete this.callbacks[event];
            }
        };
    }

    emit(event, args = []) {
        if (this.callbacks[event])
            return this.callbacks[event].map((cb) => cb(...args));
        return [];
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */