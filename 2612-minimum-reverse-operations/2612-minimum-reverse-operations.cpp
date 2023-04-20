// class Solution {
// public:
//     vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
//         vector<int> ans(n,-1);
//         ans[p] = 0;
//         if(k==1) return ans;

//         vector<bool> vis(n,false);
//         vis[p] = true;
//         for(auto& i : banned) vis[i] = true;

//         queue<int> q;
//         q.push(p);

//         while(!q.empty()){
//             int ind = q.front();

//             int best_left_l = max(0,ind-k+1);
//             int best_left_r = best_left_l+k-1;

//             int best_right_r = min(n-1,ind+k-1);
//             int best_right_l = best_right_r-k+1;

//             int l = (best_left_l + best_left_r - ind);
//             int r = (best_right_l + best_right_r - ind);

//             for(int i=l; i<=r; i+=2){
//                 if(vis[i]==true) continue;

//                 q.push(i);
//                 ans[i] = ans[ind] + 1;
//                 vis[i] = true;
//             }
//         }
//         return ans;
//     }
// };

// TC - O(n*k)



// better solution : 

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n,-1);
        ans[p] = 0;
        if(k==1) return ans;

        set<int> odd;
        set<int> even;
        for(int i=0;i<n;i++){
            if(i==p)continue;
            if(i%2) odd.insert(i);
            else even.insert(i);
        }
        for(auto& i : banned){
            if(i%2) odd.erase(i);
            else even.erase(i);
        }

        queue<int> q;
        q.push(p);

        while(!q.empty()){
            int ind = q.front();
            q.pop();

            int best_left_l = max(0,ind-k+1);
            int best_left_r = best_left_l+k-1;

            int best_right_r = min(n-1,ind+k-1);
            int best_right_l = best_right_r-k+1;

            int l = (best_left_l + best_left_r - ind);
            int r = (best_right_l + best_right_r - ind);

            if(l%2){
                vector<int> del;
                for(auto i = odd.lower_bound(l);i != odd.end() && *i<= r;i++){
                    ans[*i] = ans[ind] + 1;
                    q.push(*i);
                    del.push_back(*i);
                }
                for(auto& i : del) odd.erase(i);
            }
            else{
                vector<int> del;
                for(auto i = even.lower_bound(l);i != even.end() && *i<= r;i++){
                    ans[*i] = ans[ind] + 1;
                    q.push(*i);
                    del.push_back(*i);
                }
                for(auto& i : del) even.erase(i);
            }
        }
        return ans;
    }
};

// TC - O(n*log(n))