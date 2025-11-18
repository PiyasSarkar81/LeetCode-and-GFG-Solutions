class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        int n = position.size();
        vector<pair<double,double>> v(n);
        for(int i=0;i<n;i++){
            v[i] = {position[i], speed[i]};
        }
        sort(v.rbegin(), v.rend());
        for(int i=0;i<n;i++){
            double time = (target - v[i].first)/v[i].second;
            if(st.empty()) st.push(time);
            if(st.top() < time) st.push(time);
        }


        return st.size();
    }
};