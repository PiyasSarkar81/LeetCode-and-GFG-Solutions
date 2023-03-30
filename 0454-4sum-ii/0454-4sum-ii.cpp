class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int cnt=0;
        unordered_map<int,int> mp;
        for (auto &it1: nums1)
            for (auto &it2:nums2)
                mp[it1+it2]++; 
        for(auto &it3: nums3)
            for(auto &it4:nums4)
            {
                auto it=mp.find(0-it3-it4);
                if(it!=mp.end())
                    cnt += it->second;
            }
        
        return cnt;
    }
};