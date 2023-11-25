class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum+=num;
        vector<int> ans;
        int n = nums.size(), leftSum = 0;
        for(int i=0;i<n;i++){
            int rightSum = sum - leftSum - nums[i];

            int leftCount = i;
            int rightCount = n-i-1;

            int leftTotal = leftCount*nums[i] - leftSum;
            int rightTotal = rightSum - rightCount*nums[i];

            ans.push_back(leftTotal+rightTotal);
            leftSum += nums[i];
        }

        return ans;
    }
};