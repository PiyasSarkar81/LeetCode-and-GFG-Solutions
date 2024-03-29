class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(!n) return 0;
        sort(pairs.begin(), pairs.end());
        vector<int>lis(n,1);
        int ans =1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((pairs[j][1]<pairs[i][0]) && (lis[i]<lis[j]+1)){
                    lis[i] = lis[j]+1;
                    ans = max(ans,lis[i]);
                }
            }
        }
        return ans;
    }
};