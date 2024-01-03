class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre = 0, ans = 0;
        for(auto &row : bank){
            int cnt = 0;
            for(auto c : row){
                if(c=='1') cnt++; 
            }
            if(cnt != 0){
                ans += (cnt*pre);
                pre = cnt;
            }
        }
        return ans;
    }
};