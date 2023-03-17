class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(ans,"",n,0);
        return ans;
    }
    void fun(vector<string> &ans,string s, int n, int m){
        if(n==0 && m==0){
            ans.push_back(s);
            return;
        }
        if(n>0){
            fun(ans,s+"(",n-1,m+1);
            
        }
        if(m>0){
            fun(ans,s+")",n,m-1);
        }
        
    }
};