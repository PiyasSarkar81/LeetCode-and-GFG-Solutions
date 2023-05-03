class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1,ans2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(i==0) ans1.push_back(nums1[i]);
                if(i>0 && nums1[i-1]!=nums1[i])
                    ans1.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                if(j==0) ans2.push_back(nums2[j]);
                if(j>0 && nums2[j-1]!=nums2[j])
                    ans2.push_back(nums2[j]);
                j++;
            }
            else{
                i++;j++;
            }
        }
        while(i<nums1.size()){
            if(i==0) ans1.push_back(nums1[i]);
                if(i>0 && nums1[i-1]!=nums1[i])
                    ans1.push_back(nums1[i]);
                i++;
        }
        while(j<nums2.size()){
           if(j==0) ans2.push_back(nums2[j]);
                if(j>0 && nums2[j-1]!=nums2[j])
                    ans2.push_back(nums2[j]);
                j++;
        }
        return {ans1,ans2};
    }
};