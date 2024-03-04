class RandomizedSet {
private:
    unordered_map <int,int> map;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end()){
            return false;
        }else{
            map[val]++;
            return true;
        }
        
    }
    
    bool remove(int val) {
        auto it = map.find(val);
        if (it != map.end()) {
            if (it->second > 1) {
                it->second--; 
            } else {
                map.erase(it); 
            }
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        size_t randNo=rand()%map.size();
        auto it=map.begin();
        advance(it,randNo);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */