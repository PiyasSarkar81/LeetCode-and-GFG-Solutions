class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string ans ="";
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact *=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k -= 1;
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+(k/fact));
            if(nums.empty()) break;
            k = k%fact;
            fact = fact/nums.size();
        }
        return ans;
    }
};