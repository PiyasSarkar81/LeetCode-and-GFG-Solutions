class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[256] = {0};
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        for(int i = 0;i<n;i++){
            arr[s[i]]++;
            arr[t[i]]--;
        }

        for(int i=0;i<256;i++){
            if(arr[i]) return false;
        }
        return true;
    }
};