class Solution {
    int beautifulSubsets(vector<int>& nums,int k, unordered_map<int,int>& freq, int i){
        if(i == nums.size()) return 1;
        int result = beautifulSubsets(nums,k,freq,i+1);
        if(!freq[nums[i]-k]){
            freq[nums[i]]++;
            result += beautifulSubsets(nums,k,freq,i+1);
            freq[nums[i]]--;
        }
        return result;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        sort(nums.begin(), nums.end());
        return beautifulSubsets(nums,k,freq,0)-1;
    }
};