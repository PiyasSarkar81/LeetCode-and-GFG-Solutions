class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int maxStop = -1;
        for(auto & route : routes){
            for(int & stop : route) 
                maxStop = max(maxStop,stop);
        }
        if(maxStop < target) return -1;
        int n = routes.size();
        vector<int> minBus(maxStop+1,INT_MAX);
        minBus[source] = 0;

        bool flag = true;
        while(flag){
            flag = false;
            for(auto &route : routes){
                int mini = n+1;
                for(int stop : route) 
                    mini = min(mini,minBus[stop]);
                mini++;
                for(int stop : route){
                    if(minBus[stop]>mini){
                        minBus[stop] = mini;
                        flag = true;
                    }
                } 
            }
        }
        return (minBus[target]<n+1)?minBus[target]:-1;
    }
};