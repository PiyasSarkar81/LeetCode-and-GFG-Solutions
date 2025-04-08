class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size(), i;
        for(i=n-1;i>=0;i--){
            if(st.find(nums[i])!=st.end()) break;
            st.insert(nums[i]);
        }
        // cout<<i<<" "<<(double)i/3<<endl;
        return (int)ceil((double)(i+1)/3);
    }
};