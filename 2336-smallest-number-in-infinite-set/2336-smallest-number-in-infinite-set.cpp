class SmallestInfiniteSet {
    
    priority_queue<int,vector<int>, greater<int> > pq;
    vector<int> arr;
public:
    SmallestInfiniteSet() {
        for(int i=0;i<1000;i++){
            pq.push(i+1);
            arr.push_back(1);
        }
    }
    
    int popSmallest() {
        int t = pq.top();
        arr[t-1] = 0;
        pq.pop();
        return t;
    }
    
    void addBack(int num) {
        if(arr[num-1]==0){
            pq.push(num);
            arr[num-1]=1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */