class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(auto it : words[i]){
                mp[it]++;
            }
        }
        for(auto m : mp){
            if(m.second % n != 0)
                return false;
         }
         return true;
    }
};