class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> ans(n,0);
        st.push({temperatures[n-1],n-1});
        for(int i=n-2;i>=0;i--){
           while(!st.empty() && temperatures[i] > st.top().first) st.pop();
           if(st.empty()) st.push({temperatures[i],i});
           else {
            ans[i] = st.top().second - i;
            st.push({temperatures[i],i});
           }

        }
        return ans;
    }
};