class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        vector<int> curr = points[0];
        int ans=1;
        for(int i=0;i<n;i++){
          
            if(points[i][0]!=curr[0]||points[i][1]!=curr[1]){

                if((points[i][0]>=curr[0] && points[i][0]<=curr[1]) || (points[i][1]<=curr[1] && points[i][1]>=curr[0])){
                    curr[0] = max(points[i][0],curr[0]);
                    curr[1] = min(points[i][1],curr[1]);
                }
                else{
                    curr = points[i];
                    ans++;
                }
            }
        }
        return ans;
    }
};