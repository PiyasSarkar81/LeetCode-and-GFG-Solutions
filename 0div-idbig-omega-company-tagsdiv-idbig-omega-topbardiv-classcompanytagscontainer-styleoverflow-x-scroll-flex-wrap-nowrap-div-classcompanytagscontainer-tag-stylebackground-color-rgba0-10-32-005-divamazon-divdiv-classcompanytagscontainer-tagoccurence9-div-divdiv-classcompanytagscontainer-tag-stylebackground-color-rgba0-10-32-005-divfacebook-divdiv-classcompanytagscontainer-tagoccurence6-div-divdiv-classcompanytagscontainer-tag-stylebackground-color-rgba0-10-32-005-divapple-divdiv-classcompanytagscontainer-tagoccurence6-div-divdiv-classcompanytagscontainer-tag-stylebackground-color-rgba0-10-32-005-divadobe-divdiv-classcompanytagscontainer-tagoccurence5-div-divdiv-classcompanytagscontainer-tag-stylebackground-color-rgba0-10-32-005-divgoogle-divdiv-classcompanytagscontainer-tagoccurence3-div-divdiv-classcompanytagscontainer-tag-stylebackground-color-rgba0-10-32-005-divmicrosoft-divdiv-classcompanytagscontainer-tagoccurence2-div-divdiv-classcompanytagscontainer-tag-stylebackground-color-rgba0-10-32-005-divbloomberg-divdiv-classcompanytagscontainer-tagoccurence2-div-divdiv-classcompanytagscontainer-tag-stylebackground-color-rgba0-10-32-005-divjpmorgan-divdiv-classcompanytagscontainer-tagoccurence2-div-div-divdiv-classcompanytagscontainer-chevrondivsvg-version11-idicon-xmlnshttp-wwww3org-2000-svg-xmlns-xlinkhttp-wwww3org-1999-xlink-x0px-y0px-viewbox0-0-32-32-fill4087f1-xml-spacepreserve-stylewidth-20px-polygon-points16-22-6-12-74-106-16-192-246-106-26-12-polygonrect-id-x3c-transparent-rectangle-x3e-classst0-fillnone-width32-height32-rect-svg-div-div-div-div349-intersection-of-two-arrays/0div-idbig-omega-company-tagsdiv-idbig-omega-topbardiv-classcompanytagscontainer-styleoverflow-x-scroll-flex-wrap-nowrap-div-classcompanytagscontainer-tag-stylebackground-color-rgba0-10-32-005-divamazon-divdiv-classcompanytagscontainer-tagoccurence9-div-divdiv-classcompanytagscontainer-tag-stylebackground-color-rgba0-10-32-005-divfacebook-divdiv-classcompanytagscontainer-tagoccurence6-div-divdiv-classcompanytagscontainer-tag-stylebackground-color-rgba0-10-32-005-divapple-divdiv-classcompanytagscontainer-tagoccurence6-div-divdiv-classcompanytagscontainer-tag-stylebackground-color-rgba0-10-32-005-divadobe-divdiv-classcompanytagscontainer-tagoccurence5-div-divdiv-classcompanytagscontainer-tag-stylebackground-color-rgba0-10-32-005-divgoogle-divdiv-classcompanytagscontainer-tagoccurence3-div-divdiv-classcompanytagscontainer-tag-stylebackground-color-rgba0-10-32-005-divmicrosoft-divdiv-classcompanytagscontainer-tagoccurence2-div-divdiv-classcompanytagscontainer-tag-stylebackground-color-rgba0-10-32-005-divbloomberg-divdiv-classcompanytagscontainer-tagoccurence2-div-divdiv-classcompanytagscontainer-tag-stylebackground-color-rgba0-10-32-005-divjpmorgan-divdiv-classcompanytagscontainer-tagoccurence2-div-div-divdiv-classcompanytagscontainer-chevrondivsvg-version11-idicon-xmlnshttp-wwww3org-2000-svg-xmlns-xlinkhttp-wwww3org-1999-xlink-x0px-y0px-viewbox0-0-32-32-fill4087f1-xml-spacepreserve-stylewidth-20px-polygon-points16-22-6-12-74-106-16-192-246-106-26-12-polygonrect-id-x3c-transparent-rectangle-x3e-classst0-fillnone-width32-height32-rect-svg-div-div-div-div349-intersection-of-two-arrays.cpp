class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> ans;
        for(auto a : nums2){
            if(st.count(a)){
                ans.push_back(a);
                st.erase(a);
            }
        }
        return ans;
    }
};