class TimeMap {
    unordered_map<string,vector<pair<string,int>>> mp;
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        int ans = -1;
        int l = 0;
        int r = mp[key].size()-1;
        int mid = 0;
        while(l <= r){ 
            mid = l+(r-l)/2;
            if(mp[key][mid].second > timestamp){
                r = mid-1;
            }
            else{
                ans = mid;
                l = mid+1;
            }
        }
        if(ans==-1) return "";
        return mp[key][ans].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */