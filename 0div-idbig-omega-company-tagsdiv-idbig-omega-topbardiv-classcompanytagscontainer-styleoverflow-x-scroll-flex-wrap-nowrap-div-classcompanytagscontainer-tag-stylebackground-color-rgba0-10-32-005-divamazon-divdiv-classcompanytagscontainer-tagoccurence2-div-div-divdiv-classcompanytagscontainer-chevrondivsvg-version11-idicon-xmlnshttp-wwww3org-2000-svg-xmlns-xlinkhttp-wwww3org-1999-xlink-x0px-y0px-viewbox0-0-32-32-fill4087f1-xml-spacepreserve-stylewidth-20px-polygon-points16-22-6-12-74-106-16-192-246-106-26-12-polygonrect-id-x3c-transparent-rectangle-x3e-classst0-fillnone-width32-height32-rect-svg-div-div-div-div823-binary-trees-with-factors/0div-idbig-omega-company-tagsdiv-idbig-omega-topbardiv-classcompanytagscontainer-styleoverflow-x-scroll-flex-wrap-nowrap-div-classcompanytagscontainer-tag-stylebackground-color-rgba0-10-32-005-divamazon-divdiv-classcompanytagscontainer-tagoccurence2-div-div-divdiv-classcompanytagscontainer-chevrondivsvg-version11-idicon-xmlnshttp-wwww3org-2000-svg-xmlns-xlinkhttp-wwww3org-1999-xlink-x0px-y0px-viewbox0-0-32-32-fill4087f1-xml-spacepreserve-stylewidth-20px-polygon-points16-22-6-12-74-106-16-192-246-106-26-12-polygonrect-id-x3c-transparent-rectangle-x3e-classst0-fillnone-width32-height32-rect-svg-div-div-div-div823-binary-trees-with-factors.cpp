class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long> mp;
        mp[arr[0]] = 1;
        for(int i=0;i<arr.size();i++){
            long cnt = 1;
            for(auto it : mp){
                int rootEle = it.first;
                if(arr[i]%rootEle == 0 && mp.find(arr[i]/rootEle) != mp.end()){
                    cnt += mp[rootEle] * mp[arr[i]/rootEle];
                }
            }
            mp[arr[i]] = cnt;
        }
        int noOfTree = 0;
        for(auto it : mp){
            noOfTree = (noOfTree + it.second)%mod;
        }
        return noOfTree;
    }
};