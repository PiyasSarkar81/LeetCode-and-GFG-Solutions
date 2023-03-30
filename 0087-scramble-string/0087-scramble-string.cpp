class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n==1) return s1==s2;
        if(s1==s2 ) return true;
        
        int count[26] = {0};
        for(int i=0;i<n;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        string key=s1+" "+s2;
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        
        bool flag=false;
        
        
        for(int i=0;i<26;i++)
            if(count[i]!=0) return false;
        for(int i=1; i<n; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))){
                flag = true;
                break;
            }
                
            
            if( isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i)))
            {
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
};