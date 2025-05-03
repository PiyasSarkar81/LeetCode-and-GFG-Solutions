class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[tops[i]]++;
            mp[bottoms[i]]++;
        }
        int num = -1;
        for(auto m : mp){
            if(m.second >= n){
                num = m.first;
                break;
            } 
        }
        cout<<num<<endl;
        int topCount=0, bottomCount = 0;
        for(int i=0;i<n;i++){
            if(tops[i] == num && bottoms[i] == num) continue;
            else if(tops[i] == num) topCount++;
            else if(bottoms[i] == num) bottomCount++;
            else return -1;
        }
        return min(topCount, bottomCount);

    }
};