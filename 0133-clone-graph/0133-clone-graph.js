/**
 * // Definition for a _Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
var cloneGraph = function(node) {
    if(!node) return null
    const mp = new Map();
    const q = [node]
    mp.set(node, new Node(node.val))

    while(q.length > 0){
        const curr = q.shift();
        for( const nei of curr.neighbors){
            if(!mp.has(nei)){
                mp.set(nei, new Node(nei.val))
                q.push(nei)
            }
            mp.get(curr).neighbors.push(mp.get(nei))
        }
    }
    return mp.get(node)


};