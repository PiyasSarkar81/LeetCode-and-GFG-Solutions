class Solution {
public:
    void visit(string airport, map<string, multiset<string>>& targets, vector<string>& ans){
        
        while(targets[airport].size()){
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next, targets, ans);
        }
        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> targets;
        vector<string> ans;
        for(auto ticket : tickets){
            targets[ticket[0]].insert(ticket[1]);
        }
        visit("JFK", targets, ans);
        return vector<string>(ans.rbegin(), ans.rend());
    }
};