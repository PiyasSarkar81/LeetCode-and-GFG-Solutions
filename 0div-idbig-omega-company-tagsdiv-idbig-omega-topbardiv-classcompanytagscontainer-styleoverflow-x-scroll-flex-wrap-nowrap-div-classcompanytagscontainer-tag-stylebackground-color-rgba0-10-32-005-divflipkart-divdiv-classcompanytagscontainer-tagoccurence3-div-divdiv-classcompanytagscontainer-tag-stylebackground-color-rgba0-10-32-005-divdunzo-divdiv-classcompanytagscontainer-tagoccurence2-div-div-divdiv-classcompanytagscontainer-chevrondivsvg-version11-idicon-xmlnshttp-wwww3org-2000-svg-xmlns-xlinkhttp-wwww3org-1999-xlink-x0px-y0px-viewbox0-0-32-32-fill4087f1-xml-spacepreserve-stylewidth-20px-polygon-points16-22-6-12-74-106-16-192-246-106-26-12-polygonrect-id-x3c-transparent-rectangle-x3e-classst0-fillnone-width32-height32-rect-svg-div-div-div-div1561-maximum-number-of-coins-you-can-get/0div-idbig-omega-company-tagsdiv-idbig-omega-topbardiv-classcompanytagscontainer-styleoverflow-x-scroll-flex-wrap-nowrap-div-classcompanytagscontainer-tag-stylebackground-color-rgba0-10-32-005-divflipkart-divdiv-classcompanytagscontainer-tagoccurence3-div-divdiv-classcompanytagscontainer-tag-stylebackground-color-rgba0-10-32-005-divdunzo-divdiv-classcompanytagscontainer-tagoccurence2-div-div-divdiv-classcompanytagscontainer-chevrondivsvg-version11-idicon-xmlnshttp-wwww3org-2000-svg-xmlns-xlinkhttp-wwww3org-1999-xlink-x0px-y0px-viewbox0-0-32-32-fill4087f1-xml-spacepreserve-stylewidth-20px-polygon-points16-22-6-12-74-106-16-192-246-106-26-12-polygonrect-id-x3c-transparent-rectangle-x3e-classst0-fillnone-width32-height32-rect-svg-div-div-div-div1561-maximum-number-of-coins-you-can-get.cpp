class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int triplets = n/3;
        priority_queue<int> pq;
        for(auto pile : piles) pq.push(pile);
        int ans = 0;
        while(triplets--){
            pq.pop();
            cout<<pq.top()<<" ";
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};