class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> lost;
        for(auto m : matches){
            if(!lost.count(m[0])) lost[m[0]] = 0;
            lost[m[1]]++;
        }

        vector<int> zeros,ones;
        for(auto[k,v] : lost){
            if(v == 0) zeros.push_back(k);
            if(v == 1) ones.push_back(k);
        }
        return {zeros,ones};

    }
};