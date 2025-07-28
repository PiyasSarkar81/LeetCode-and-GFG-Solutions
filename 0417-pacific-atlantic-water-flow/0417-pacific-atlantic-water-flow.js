/**
 * @param {number[][]} heights
 * @return {number[][]}
 */
var pacificAtlantic = function(heights) {
    const m = heights.length, n = heights[0].length;
    const pacific = new Set(), atlantic = new Set();

    const bfs = (queue, visited) => {
        while (queue.length) {
            const [r, c] = queue.shift();
            visited.add(`${r},${c}`);
            for (const [dr, dc] of [[1,0],[-1,0],[0,1],[0,-1]]) {
                const nr = r + dr, nc = c + dc;
                const key = `${nr},${nc}`;
                if (
                    nr >= 0 && nc >= 0 && nr < m && nc < n &&
                    !visited.has(key) &&
                    heights[nr][nc] >= heights[r][c]
                ) {
                    queue.push([nr, nc]);
                    visited.add(key);
                }
            }
        }
    };

    const pacQ = [], atlQ = [];
    for (let i = 0; i < m; i++) {
        pacQ.push([i, 0]);
        atlQ.push([i, n - 1]);
    }
    for (let j = 0; j < n; j++) {
        pacQ.push([0, j]);
        atlQ.push([m - 1, j]);
    }

    bfs(pacQ, pacific);
    bfs(atlQ, atlantic);

    const result = [];
    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            const key = `${r},${c}`;
            if (pacific.has(key) && atlantic.has(key)) {
                result.push([r, c]);
            }
        }
    }

    return result;
};