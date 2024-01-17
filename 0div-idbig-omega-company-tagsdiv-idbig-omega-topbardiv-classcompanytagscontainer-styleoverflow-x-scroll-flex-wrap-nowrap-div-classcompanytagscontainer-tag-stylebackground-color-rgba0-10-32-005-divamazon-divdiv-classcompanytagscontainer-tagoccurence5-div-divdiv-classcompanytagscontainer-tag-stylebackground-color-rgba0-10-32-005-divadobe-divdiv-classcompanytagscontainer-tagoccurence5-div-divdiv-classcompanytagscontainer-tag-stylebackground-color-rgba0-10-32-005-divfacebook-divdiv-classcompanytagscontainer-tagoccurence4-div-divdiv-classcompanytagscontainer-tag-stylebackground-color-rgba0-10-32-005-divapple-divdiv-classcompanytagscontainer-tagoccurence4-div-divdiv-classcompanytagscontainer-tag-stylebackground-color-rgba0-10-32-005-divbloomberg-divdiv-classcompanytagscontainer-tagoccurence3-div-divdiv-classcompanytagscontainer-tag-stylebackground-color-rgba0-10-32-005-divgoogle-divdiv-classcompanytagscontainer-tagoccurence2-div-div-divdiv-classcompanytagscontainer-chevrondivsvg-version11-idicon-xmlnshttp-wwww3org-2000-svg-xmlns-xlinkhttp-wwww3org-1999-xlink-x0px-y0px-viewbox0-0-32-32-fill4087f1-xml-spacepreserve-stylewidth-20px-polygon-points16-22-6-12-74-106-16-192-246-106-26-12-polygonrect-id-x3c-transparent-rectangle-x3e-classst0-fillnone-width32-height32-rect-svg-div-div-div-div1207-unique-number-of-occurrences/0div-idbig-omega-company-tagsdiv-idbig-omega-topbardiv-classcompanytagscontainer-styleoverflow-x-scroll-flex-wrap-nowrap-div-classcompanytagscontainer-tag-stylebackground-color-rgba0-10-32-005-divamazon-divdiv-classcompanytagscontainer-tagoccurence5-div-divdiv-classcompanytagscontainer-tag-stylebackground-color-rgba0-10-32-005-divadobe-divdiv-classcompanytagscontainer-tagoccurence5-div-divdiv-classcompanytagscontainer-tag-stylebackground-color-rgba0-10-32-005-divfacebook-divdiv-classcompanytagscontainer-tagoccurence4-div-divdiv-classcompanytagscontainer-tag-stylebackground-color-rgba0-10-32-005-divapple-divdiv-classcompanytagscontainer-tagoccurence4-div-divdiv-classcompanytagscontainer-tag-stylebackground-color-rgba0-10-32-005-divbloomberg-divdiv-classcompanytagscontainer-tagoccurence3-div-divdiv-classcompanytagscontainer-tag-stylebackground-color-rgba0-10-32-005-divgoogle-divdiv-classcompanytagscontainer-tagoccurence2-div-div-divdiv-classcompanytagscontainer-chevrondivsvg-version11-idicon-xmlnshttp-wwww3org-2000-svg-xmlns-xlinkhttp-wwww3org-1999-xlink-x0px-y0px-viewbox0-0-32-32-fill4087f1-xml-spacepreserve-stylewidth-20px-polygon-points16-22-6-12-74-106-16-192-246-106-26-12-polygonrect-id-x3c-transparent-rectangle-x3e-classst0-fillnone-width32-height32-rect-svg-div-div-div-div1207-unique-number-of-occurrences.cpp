class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(auto a : arr){
            freq[a]++;
        }
        vector<int> rep;
        for(auto m : freq){
            if(find(rep.begin(), rep.end(), m.second) != rep.end()){
                return false;
            }
            else rep.push_back(m.second);
        }
        return true;
    }
};