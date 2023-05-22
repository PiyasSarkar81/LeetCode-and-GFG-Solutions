/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    if(object === null || object === undefined) return String(object);
    if(Array.isArray(object)) {   // Array []
        const values = object.map((obj) => jsonStringify(obj));
        return `[${values.join(",")}]`;
    }
    if(typeof object === 'object') { // Objects {}
        const keys = Object.keys(object);
        const keyValuePairs = keys.map((key) => `"${key}":${jsonStringify(object[key])}`);
        return `{${keyValuePairs.join(",")}}`;
    }
    if(typeof object === 'string') {  // String ""
        return `"${String(object)}"`;
    }
    return String(object); // boolian or number
};