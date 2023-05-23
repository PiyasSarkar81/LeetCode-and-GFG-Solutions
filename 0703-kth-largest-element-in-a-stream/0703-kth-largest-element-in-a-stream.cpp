class KthLargest {
    int k;
    multiset<int> arr;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto &num: nums) arr.insert(num);
        while(arr.size()>k) arr.erase(arr.begin());
    }
    
    int add(int val) {
        arr.insert(val);
        while(arr.size() >k) arr.erase(arr.begin());
        return *arr.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */