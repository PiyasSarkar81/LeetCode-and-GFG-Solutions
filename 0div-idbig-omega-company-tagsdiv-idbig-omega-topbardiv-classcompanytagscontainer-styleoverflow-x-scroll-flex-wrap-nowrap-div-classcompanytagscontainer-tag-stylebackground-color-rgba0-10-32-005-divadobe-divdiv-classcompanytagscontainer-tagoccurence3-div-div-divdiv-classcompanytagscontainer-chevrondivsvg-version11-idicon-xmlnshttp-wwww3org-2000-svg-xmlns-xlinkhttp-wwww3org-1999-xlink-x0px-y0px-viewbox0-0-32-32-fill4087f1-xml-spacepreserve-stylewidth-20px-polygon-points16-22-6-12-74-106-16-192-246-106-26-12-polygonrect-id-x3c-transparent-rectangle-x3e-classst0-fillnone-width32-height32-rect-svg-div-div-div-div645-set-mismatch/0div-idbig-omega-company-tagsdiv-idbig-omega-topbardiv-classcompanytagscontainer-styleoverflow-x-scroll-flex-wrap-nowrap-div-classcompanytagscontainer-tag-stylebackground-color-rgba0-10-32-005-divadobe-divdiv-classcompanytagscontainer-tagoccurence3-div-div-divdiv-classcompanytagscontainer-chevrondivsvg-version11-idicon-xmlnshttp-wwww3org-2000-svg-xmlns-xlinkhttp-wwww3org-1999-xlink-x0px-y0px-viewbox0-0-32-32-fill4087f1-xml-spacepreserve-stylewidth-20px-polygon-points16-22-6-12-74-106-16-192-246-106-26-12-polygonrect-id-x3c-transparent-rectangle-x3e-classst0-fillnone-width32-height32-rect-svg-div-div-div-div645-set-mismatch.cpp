class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup,miss, n = nums.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            v[nums[i]-1]++;
        }
        for(int i=0;i<n;i++){
            if(v[i] == 2) dup = i+1;
            if(v[i] == 0) miss = i+1; 
        }
        return {dup,miss};
    }
};