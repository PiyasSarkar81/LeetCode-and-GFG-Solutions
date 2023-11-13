class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch =='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'; 
    }
    string sortVowels(string s) {
        unordered_map<char,int>mp;
        string t = s;
        for(int i=0;i<s.size();i++)
            if(isVowel(s[i])) 
                mp[s[i]]++;
        string sortedVowel = "AEIOUaeiou";
        int j = 0;
        for(int i=0;i<s.size();i++)
            if(isVowel(t[i])){
                while(mp[sortedVowel[j]]==0)j++;
                t[i] = sortedVowel[j];
                mp[sortedVowel[j]]--;
            }
        return t;
    }
};