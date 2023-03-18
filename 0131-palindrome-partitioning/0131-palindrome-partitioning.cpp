class Solution {
public:
    bool isPalindrom(string s){
        int l = 0;
        int r = s.size() -1;
        while(l<r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    void helper(vector<vector<string>> &ans, vector<string> &temp, string s){
        if(s.size() == 0){
            ans.push_back(temp);
        }
        for(int i = 0;i<s.size(); i++){
            string leftstr = s.substr(0,i+1);
            if(isPalindrom(leftstr)){
                temp.push_back(leftstr);
                helper(ans,temp,s.substr(i+1));
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(ans,temp,s);
        return ans;
    }
};