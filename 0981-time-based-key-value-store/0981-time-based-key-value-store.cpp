class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp; 
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
        sort(mp[key].rbegin(), mp[key].rend());
    }
    
    string get(string key, int timestamp) {
        for(auto a : mp[key]){
            if(a.first <= timestamp) return a.second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */