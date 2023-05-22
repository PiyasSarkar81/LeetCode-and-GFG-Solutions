class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto a : nums) {
            mp[a]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto m : mp) {
            pq.push({m.second, m.first});
            if(pq.size() > (int)mp.size()-k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};