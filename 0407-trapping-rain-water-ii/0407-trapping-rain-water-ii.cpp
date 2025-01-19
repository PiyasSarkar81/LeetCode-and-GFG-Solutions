class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(),n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int water = 0;
        int currentLevel = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!minHeap.empty()) {
            auto cell = minHeap.top();
            minHeap.pop();
            int height = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            currentLevel = max(currentLevel, height);

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    if (heightMap[nx][ny] < currentLevel) {
                        water += currentLevel - heightMap[nx][ny];
                    }

                    minHeap.push({heightMap[nx][ny], {nx, ny}});
                }
            }
        }

        return water;
    }
};