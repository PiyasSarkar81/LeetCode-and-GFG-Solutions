class Solution {
public:
    
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
        }
        long long int add = goal - sum;
        return (abs(add)/limit + ((abs(add)%limit)? 1 : 0 ));
    }
};