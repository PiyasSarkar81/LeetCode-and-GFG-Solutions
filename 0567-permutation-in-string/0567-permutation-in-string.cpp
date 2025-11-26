class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1, mp2;
        int n = s1.size(), m = s2.size();
        for(auto c : s1) mp1[c]++;
        if(m<n) return false;
        for(int i=0;i<n;i++){
            mp2[s2[i]]++;
        }
        int i = n;
        if(mp1 == mp2) return true;
        while(i<m){
            mp2[s2[i]]++;
            mp2[s2[i-n]]--;

            if(mp2[s2[i-n]] == 0)  
                mp2.erase(s2[i-n]);
            if(mp1 == mp2) return true;
            i++;
        }
        return false;
    }
};