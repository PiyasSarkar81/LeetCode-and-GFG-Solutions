class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>& nums,int i,vector<int> t){
        if(i==nums.size()){
            ans.push_back(t);
            return;
        }
        fun(nums,i+1,t);
        t.push_back(nums[i]);
        fun(nums,i+1,t);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        fun(nums,0,temp);
        return ans;
    }
};