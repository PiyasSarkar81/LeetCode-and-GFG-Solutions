class Solution {
public:

    bool isPossible(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == 1)
            return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        int pathLength = 1;

        while(!q.empty()) {
            int size = q.size();

            for(int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i == n - 1 && j == m - 1) {
                    return pathLength;
                }

                vector<pair<int, int>> directions = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

                for(auto dir : directions) {
                    int newI = i + dir.first;
                    int newJ = j + dir.second;

                    if(isPossible(newI, newJ, n, m, grid, vis)) {
                        q.push({newI, newJ});
                        vis[newI][newJ] = true;
                    }
                }
            }

            pathLength++;
    }

    return -1;
    }
};