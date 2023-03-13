class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        int c,x;
        for(int i = 1;i<=n;i++){
            x = i;
            c = 0;
            while(x){
                c++;
                x = x & (x-1);
            }
            ans.push_back(c);
        }
        return ans;
    }
};