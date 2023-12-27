class Solution {
    struct node{
        char color;
        int cost;
    };
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<node> st;
        int n = colors.size();
        int ans =  0;

        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().color == colors[i]){
                if(st.top().cost < neededTime[i]){
                    ans += st.top().cost;
                    st.pop();
                    st.push({colors[i],neededTime[i]});

                }
                else ans += neededTime[i];
            }
            else{
                st.push({colors[i],neededTime[i]});
            }
        }
        return ans;
    }
};