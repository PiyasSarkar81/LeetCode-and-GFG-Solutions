#define pii pair<int,pair<int,int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n =  heights.size(), m = heights[0].size();
       int dx[] = {0,0,1,-1};
       int dy[] = {1,-1,0,0};
       priority_queue<pii,vector<pii>,greater<pii>> pq;
       vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
       dis[0][0] =0;
       pq.push({0,{0,0}});

       while(!pq.empty()){
           pii curr = pq.top();pq.pop();
           int d = curr.first, r = curr.second.first, c = curr.second.second;
           if(r==n-1 && c ==m-1) return d;
           for(int i=0;i<4;i++){
               int nr = r + dx[i], nc = c + dy[i];
               if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
               int nd = max(d,abs(heights[nr][nc]-heights[r][c]));
               if(nd < dis[nr][nc]){
                   dis[nr][nc] = nd;
                   pq.push({nd,{nr,nc}});
               }
           }
       }
       return 0;
    }
};