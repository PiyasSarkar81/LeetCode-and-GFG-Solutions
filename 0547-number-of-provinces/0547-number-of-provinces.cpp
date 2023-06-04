class Solution {
public:
    void countPro(vector<vector<int>>& isConnected,vector<bool>& pro, int i){
        if(pro[i]==true) return;
        pro[i]=true;
        int n = pro.size();
        for(int j =0;j<n;j++){
            
            if(isConnected[i][j] == 1 && i!= j){
                countPro(isConnected,pro,j);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>pro(n,false);
        int ans =0;
        for(int i =0;i<n;i++){
            if(pro[i]==false)ans++;
            countPro(isConnected,pro,i);
        }
        return ans;
    }
};