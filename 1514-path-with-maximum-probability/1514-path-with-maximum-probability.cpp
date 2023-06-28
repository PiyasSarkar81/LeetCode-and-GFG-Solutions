class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n,0);
        vector<pair<int, double>> adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        } 

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        prob[start] = 1.0;

        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto a: adj[currNode]){
                if(prob[a.first] < currProb * a.second){
                    prob[a.first] = currProb*a.second;
                    pq.push({prob[a.first], a.first});
                }
            }
        }
        return prob[end];
    }
};