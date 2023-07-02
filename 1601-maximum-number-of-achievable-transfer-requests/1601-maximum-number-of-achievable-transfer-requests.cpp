class Solution {
public:
    void maxRequest(vector<vector<int>>& requests,vector<int>& indegree,int n,int idx, int count, int& ans){
        if(idx == requests.size()){
            for(int i =0;i<n;i++){
                if(indegree[i]) return;
            }
            ans = max(ans,count);
            return;
        }

        indegree[requests[idx][0]]--;
        indegree[requests[idx][1]]++;
        maxRequest(requests,indegree,n,idx+1,count+1,ans);
        indegree[requests[idx][0]]++;
        indegree[requests[idx][1]]--;
        maxRequest(requests,indegree,n,idx+1,count,ans);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans =0;
        vector<int> indegree(n,0);
        maxRequest(requests,indegree,n,0,0,ans);
        return ans;
    }
};