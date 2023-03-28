class Solution {
public:
    struct node{
        int no;
        int freq;
        node(int a,int b){
            no = a;
            freq = b;
        }
    };
    struct compare{
        bool operator()(node const& a, node const& b){
            return a.freq < b.freq;
        }  
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto ele : nums){
            mp[ele] += 1;
        }
        
        priority_queue<node,vector<node>,compare> heap;
        for(auto it: mp){
            heap.push(node(it.first,it.second));
        }
        vector<int> ans;
        while(k--){
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};