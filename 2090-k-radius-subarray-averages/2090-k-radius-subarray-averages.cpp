class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(),m=2*k+1;
        long long int s=0;
        vector<int>ans(n,-1);
        int c=0,j=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            c+=1;
            if(c==m){
                ans[i-k]=s/m;
                s-=nums[j];
                j++;
                c-=1;
            }
        }
        return ans;
    }
};