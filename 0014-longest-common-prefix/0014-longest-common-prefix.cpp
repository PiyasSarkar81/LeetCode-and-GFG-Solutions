class Solution {
public:
    string solve(string str1, string str2){
        int n = str1.size();
        string ans="";
        for(int i =0;i<n;i++){
            if(str1[i]==str2[i]) ans += str1[i];
            else return ans;
        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        sort(strs.begin(),strs.end());
        string ans = "";
        ans += solve(strs[0],strs[n-1]);
        return ans;
    }
};