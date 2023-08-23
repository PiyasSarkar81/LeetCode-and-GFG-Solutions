class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCount(26,0);
        for(auto c : s){
            charCount[c-'a']++;
        }
        // Max heap order by carecter count
        priority_queue<vector<int>> pq;
        for(int i=0;i<26;i++){
            if(charCount[i]>0){
                pq.push({charCount[i],i+'a'});
            }
        }

        string ans;
        while(!pq.empty()){
            auto first = pq.top();
            pq.pop();
            if(ans.empty() || first[1]!=ans.back()){
                ans += (char)first[1];
                if(--first[0]>0){
                    pq.push(first);
                }
            }else{
                if(pq.empty()){
                    return "";
                }
                auto second = pq.top();
                pq.pop();
                ans += (char)second[1];
                if(--second[0]>0){
                    pq.push(second);
                }
                pq.push(first);
            }
        }
        return ans;
    }
};