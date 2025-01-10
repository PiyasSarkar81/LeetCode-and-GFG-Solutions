class Solution {
public:
    bool checkWords(const string& word, const array<int, 26>& lettersSubword) {
        array<int, 26> lettersWord = {};
        for (char ch : word) {
            ++lettersWord[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (lettersWord[i] < lettersSubword[i]) {
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        array<int, 26> merge = {}; 
        for (const auto& subword : words2) {
            array<int, 26> letters = {}; 
            for (char ch : subword) {
                ++letters[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                merge[i] = max(merge[i], letters[i]);
            }
        }
        for (const auto& word : words1) {
            if (checkWords(word, merge)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
};