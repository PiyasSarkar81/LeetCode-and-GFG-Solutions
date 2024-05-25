class Solution {

    unordered_map<string,vector<string>> m;
    vector<string> combine(string str, vector<string> prev){
        for(int i =0;i<prev.size();i++){
            prev[i] += " "+str;
        }
        return prev;
    }
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s)) return m[s];
        vector<string> result;
        for(auto dict : wordDict){
            if(dict == s){
                result.push_back(s);
            }
        }
        for(int i = 1;i<s.size();i++){
            string words = s.substr(i);
            for(auto dict : wordDict){
            if(dict == words){
                string rem = s.substr(0,i);
                vector<string> prev = combine(words,wordBreak(rem,wordDict));
                result.insert(result.end(),prev.begin(),prev.end());
            }
            }
        }
        m[s] = result;
        return result;
    }
};