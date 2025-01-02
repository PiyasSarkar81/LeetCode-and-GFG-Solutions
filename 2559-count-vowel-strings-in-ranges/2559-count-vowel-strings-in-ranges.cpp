class Solution {
public:
    bool isVowel(char c){
        vector<int> v = {'a','e','i','o','u'};
        return find(v.begin(), v.end(), c) != v.end();
     }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> cnts(n,0);
        for(int i=0;i< words.size();i++){
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1])) cnts[i] = 1;
        } 
        vector<int> prefixsum(n,0);
        prefixsum[0] = cnts[0];
        for(int i=1;i<n;i++) prefixsum[i] = prefixsum[i-1] + cnts[i];
        int q = queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int f = queries[i][0], s = queries[i][1];
            ans[i] = prefixsum[s] - prefixsum[f] + cnts[f];
         }

        return ans;
    }
};