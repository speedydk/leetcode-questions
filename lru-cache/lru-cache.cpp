class LRUCache {
    list<pair<int, int> > lst;
    int capacity, count;
    unordered_map<int, list<pair<int, int> >::iterator> cache;
public:
    LRUCache(int capacity): capacity(capacity) {
        
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
		// insert the current key, value at the end of the list
        lst.push_back({key, (*cache[key]).second});
		//delete the node pointed by the key in the map
        lst.erase(cache[key]);
        
        auto it = lst.end(); --it;
        cache[key] = it;
        
        return (*cache[key]).second;
    }
    
    void put(int key, int value) {
        
        if (cache.find(key) != cache.end()) {
            lst.erase(cache[key]);
            lst.push_back({key, value});
            auto it = lst.end(); --it;
            cache[key] = it;
            
            return;
        }
        
        if (cache.size() == capacity) {
            int LRUKey = lst.front().first;
            lst.erase(lst.begin());
            cache.erase(LRUKey);
        }
        
        lst.push_back({key, value});
        auto it = lst.end(); --it;
        cache[key] = it;
    }
};