class Solution {
public:
    int minOperations(vector<int>& nums) {
       int ans = 0;
       unordered_map<int,int> mp;
       for(auto &num : nums){
           mp[num]++;
       } 
       for(auto &[k,v] : mp){
           if(v == 1) return -1;
           ans += v/3 + (v%3 > 0);
       }
       return ans;
    }
};