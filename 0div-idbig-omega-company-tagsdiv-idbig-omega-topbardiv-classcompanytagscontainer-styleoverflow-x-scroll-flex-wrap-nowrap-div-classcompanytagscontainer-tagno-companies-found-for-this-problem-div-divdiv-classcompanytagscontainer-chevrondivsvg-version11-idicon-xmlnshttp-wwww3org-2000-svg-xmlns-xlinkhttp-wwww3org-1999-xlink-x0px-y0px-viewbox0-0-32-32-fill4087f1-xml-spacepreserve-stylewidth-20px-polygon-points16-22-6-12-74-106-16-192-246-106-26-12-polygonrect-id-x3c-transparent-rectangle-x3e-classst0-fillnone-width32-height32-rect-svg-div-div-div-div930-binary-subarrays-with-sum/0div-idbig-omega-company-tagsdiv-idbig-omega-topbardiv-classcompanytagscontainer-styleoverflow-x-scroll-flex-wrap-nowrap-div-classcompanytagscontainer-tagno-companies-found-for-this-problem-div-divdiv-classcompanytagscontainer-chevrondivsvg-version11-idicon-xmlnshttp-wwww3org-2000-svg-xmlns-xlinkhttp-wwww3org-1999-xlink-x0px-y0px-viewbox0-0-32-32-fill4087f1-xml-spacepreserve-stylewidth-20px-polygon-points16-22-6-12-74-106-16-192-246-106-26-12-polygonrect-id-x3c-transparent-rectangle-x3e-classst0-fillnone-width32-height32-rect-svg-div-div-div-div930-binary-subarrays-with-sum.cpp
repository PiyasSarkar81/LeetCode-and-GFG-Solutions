class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m({{0,1}});
        int psum = 0,ans=0;
        for(auto num : nums){
            psum += num;
            ans += m[psum-goal];
            m[psum]++;
        }
        return ans;
    }
};