class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,int> mp;
    string b;

    void dfs(string word, vector<string>& seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int stapes = mp[word];
        int sz = word.size();
        for(int i=0;i<sz;i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(mp.find(word)!=mp.end() && mp[word] + 1 == stapes){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        b = beginWord;
        queue<string>q;
        q.push(beginWord);
        mp[beginWord]=1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int stapes = mp[word];
            q.pop();
            if(word == endWord) break;
            for(int i=0;i<sz;i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mp[word] = stapes + 1;
                    }
                }
                word[i] = original;
            }
        }

        if(mp.find(endWord)!=mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};