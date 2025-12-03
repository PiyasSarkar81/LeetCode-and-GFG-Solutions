class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto n : nums){
            if(st.find(n) != st.end()) return n;
            else st.insert(n);
        }
        return -1;

    }
};