class Solution {
public:
    string reverseWords(string s) {
        string ans="",temp="";
        for(int i =s.size()-1;i>=0;i--){
            if(s[i] != ' '){
                temp += s[i];
            } else {
                if(temp=="") continue;
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += ' ';
                temp = "";
            }
        }
        if(temp!=""){
            reverse(temp.begin(),temp.end());
            ans += temp;
        }
        if(ans[ans.size()-1]==' ') ans.erase(ans.size()-1);
        return ans;
    }
};