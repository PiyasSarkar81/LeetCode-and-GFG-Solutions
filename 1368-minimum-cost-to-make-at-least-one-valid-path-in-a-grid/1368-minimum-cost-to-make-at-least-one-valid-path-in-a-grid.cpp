class Solution {
public:
    #define p pair<int, pair<int,int>>
    bool isPossible(int r, int c, vector<vector<bool>>& vis){
        return r>=0 && c>=0 && r<vis.size() && c<vis[0].size() && vis[r][c] == false; 
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first, r= it.second.first, c= it.second.second;
            if(vis[r][c]) continue;
            vis[r][c] = true;
            if(r == n-1 && c == m-1) return d;

            int newDir = grid[r][c] - 1;
            int nr = r + dir[newDir][0];
            int nc = c + dir[newDir][1];
            if(isPossible(nr,nc,vis)) pq.push({d,{nr,nc}});
            for(int i=0;i<4;i++){
                if(i == newDir) continue;
                nr = r + dir[i][0], nc = c + dir[i][1];
                if(isPossible(nr,nc,vis)) pq.push({d+1,{nr,nc}}); 
            }

        } 
        return -1;
    }
};