class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto num : nums){
            if(m.find(num) == m.end()){
                m[num] = 1;
            }else{
                m[num] = -1;
            }
        }
        for(auto a : m){
            if(a.second == 1) return a.first; 
        }
        return 0;
    }
};