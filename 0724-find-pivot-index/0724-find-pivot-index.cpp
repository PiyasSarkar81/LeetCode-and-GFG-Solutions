#define ll long long int
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int totalSum = 0;
        int leftsum = 0;
        for (int ele : nums)
            totalSum += ele;
        for (int i = 0; i < nums.size(); leftsum += nums[i++])
            if (leftsum * 2 == totalSum - nums[i])
                return i;       
        return -1; 
    }
};