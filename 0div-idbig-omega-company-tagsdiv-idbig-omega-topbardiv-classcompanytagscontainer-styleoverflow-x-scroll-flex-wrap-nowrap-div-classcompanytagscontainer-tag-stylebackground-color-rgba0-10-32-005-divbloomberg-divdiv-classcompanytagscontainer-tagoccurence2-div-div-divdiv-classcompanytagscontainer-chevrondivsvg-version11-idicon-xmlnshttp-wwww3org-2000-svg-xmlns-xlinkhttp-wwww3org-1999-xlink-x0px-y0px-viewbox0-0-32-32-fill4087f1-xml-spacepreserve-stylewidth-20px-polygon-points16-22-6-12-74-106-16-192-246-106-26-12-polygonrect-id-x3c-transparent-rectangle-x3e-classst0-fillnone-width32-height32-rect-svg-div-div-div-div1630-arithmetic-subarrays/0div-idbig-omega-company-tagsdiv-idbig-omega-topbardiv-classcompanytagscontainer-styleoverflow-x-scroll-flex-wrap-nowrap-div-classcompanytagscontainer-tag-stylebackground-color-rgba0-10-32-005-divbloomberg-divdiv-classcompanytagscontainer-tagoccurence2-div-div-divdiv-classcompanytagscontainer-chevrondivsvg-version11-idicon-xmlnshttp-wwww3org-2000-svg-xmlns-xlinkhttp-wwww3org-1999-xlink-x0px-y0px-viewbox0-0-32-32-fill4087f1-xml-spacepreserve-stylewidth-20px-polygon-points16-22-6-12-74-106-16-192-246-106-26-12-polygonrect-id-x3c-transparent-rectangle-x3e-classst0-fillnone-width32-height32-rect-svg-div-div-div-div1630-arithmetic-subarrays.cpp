class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n= nums.size(), m = l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++){
            int lp = l[i], rp = r[i];
            vector<int> temp(nums.begin()+lp,nums.begin()+rp+1);
            sort(temp.begin(),temp.end());
            int k = temp.size();
            if(k<2){
                ans.push_back(false);
                continue;
            }
            int d= temp[1]-temp[0];
            for(int i=1;i<k;i++){
                if(temp[i] - temp[i-1] != d){
                    ans.push_back(false);
                    break;
                }
            }
            if(ans.size() == i+1) {
                continue;
            }
            ans.push_back(true);
        }
        return ans;
    }
};