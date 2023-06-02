class Solution {
public:
    typedef long long int ll;

    // Check if(x2, y2) lie within the proximity of (x1, y1)
    bool check(ll x1,ll y1,ll x2, ll y2, ll d){
        ll x = pow(x1-x2,2);
        ll y = pow(y1-y2,2);

        return (x+y <= pow(d,2));
    }

    // count the number of other nodes that can be detonated
    // from the current node
    int detonated(vector<vector<int>>& adj,vector<bool>& vis, int node, int n){
        int cnt =1;
        vis[node] = true;

        for(auto &adjnode : adj[node]) {
            if(!vis[adjnode]){
                cnt += detonated(adj, vis, adjnode, n);
            }
        }

        return cnt;
    }
     


    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        int maxBombs = 0;

        vector<vector<int>> deto_adj(n);

        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && check(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])) {
                    deto_adj[i].push_back(j);
                }
            }
        }


        for(int i =0;i<n;i++){
            vector<bool> vis(n,false);

            maxBombs = max(maxBombs, detonated(deto_adj, vis, i, n));
        }

        return maxBombs;
    }
};