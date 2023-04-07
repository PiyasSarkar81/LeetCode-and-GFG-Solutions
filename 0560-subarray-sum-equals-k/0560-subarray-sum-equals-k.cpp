class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n==0) return 0;
        
        unordered_map<int,int> m;
        int sum =0;
        int i=0;
        int cnt =0;
        
        while(i<n){
            sum += nums[i];
            
            if(sum == k) cnt++;
            if(m.find(sum-k)!=m.end()) cnt += m[sum-k];
            
            m[sum]++;
            
            i++;
        }
        return cnt;
    }
};