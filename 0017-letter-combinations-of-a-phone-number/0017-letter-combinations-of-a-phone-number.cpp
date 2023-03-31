class Solution {
public:
    void solve(int i, string& s,string& temp,vector<string>& ans,unordered_map<char,string>& mp ){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        string str = mp[s[i]];
        for(int j=0;j<str.size();j++){
            temp.push_back(str[j]);
            solve(i+1,s,temp,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4'] ="ghi";
        mp['5']= "jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        
        vector<string> ans;
        if(digits == "") return ans;
        string temp;
        solve(0,digits,temp,ans,mp);
        return ans;
    }
};