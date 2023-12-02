class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> c1(26,0);
        for(int i=0;i<chars.size();i++){
            c1[chars[i]-'a']++;
        }
        for(auto word : words){
            vector<int> c(26,0);
            for(int i=0;i<word.size();i++)
                c[word[i]-'a']++;
            int i;
            for( i=0;i<26;i++)
                if(c[i]>c1[i])
                    break;
            if(i==26) ans += word.size();
        }
        return ans;
    }
};