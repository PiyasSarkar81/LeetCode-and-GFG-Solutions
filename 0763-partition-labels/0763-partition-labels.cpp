class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int start = 0, end = 0, n = s.size();
        vector<int> lastOccr(26,0);
        for(int i=0;i<n;i++){
            lastOccr[s[i]-'a'] = i;
        }
        for(int i=0;i<n;i++){
            end = max(end, lastOccr[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};