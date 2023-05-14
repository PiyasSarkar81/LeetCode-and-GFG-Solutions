class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // set<int>hashSet;
        // for(int num : nums){
        //     hashSet.insert(num);
        // }
        // int longestStreak =0;
        // for(int num:nums){
        //     if(!hashSet.count(num-1)){
        //         int currentNum =num;
        //         int currentStreak =1;
        //         while(hashSet.count(currentNum+1)){
        //             currentNum += 1;
        //             currentStreak += 1;
        //         }
        //         longestStreak = max(longestStreak,currentStreak);
        //     }
        // }
        // return longestStreak;
        

        if(nums.size() == 0) return 0;
        int cnt = 1, maxLength = 1;
        sort(nums.begin(), nums.end());
        for(int i =1;i<nums.size();i++) {
            if(nums[i] != nums[i-1]) {
                if(nums[i] == nums[i-1] + 1) {
                    cnt++;
                } else {
                    maxLength = max(maxLength, cnt);
                    cnt = 1;
                }
            }
        }
        return max(maxLength, cnt);
    }
};