class TimeMap {
private:
     unordered_map<string,map<int,string>> result;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        result[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(result.find(key)==result.end())
            return "";
        auto& values = result[key];
        auto it = values.upper_bound(timestamp);
        if (it == values.begin())
            return "";

        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */