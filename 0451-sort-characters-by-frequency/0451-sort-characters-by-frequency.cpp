class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++ ){
            mp[s[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto m:mp){
            pq.push({m.second,-m.first});
        }
        string ans = "";
        while(!pq.empty()){
            int ele = pq.top().first;
            while(ele--){
                ans += (char)abs(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};