

class LRUCache {
     list<int>l;
     unordered_map<int,pair<list<int>::iterator, int>>m;
     int size;
public:
    LRUCache(int capacity) {
         size = capacity;
    }
    
    void moveToFirst(int key){
        l.erase(m[key].first);
        l.push_front(key);
        m[key].first = l.begin();
    }

    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        moveToFirst(key);
        return m[key].second;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key].second = value;
            moveToFirst(key);
        }
        else{
            l.push_front(key);
            m[key]={l.begin(),value};
            size--;
        }
        if(size<0){
            m.erase(l.back());
            l.pop_back();
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */