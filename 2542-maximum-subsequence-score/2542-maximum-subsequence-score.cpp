class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = size(nums1);
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i].first = nums2[i];
            pairs[i].second = nums1[i];
        }
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long ans = 0, sum = 0;
        for (auto& [a, b] : pairs) {
            pq.push(b);
            sum += b;
            if (size(pq) > k) sum -= pq.top(), pq.pop();
            if (size(pq) == k) ans = max(ans, sum * a);
        }
        return ans;        
    }
};