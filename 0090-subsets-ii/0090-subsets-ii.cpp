class Solution {
public:
    void subArr(vector<int>& nums,vector<vector<int>>& ans,int index,vector<int>& res){
        ans.push_back(res);
        for(int i =index;i<nums.size();i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            res.push_back(nums[i]);
            subArr(nums,ans,i+1,res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(),nums.end());
        subArr(nums,ans,0,res);
        return ans;
    }
};