class TimeMap {
public:
map<string,vector<int>> timeStampForKey;
map<string,map<int,string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key][timestamp] = value;
        timeStampForKey[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        
        if(timeStampForKey.find(key)==timeStampForKey.end()) return "";
        // get last updated timestamp
        int idx = upper_bound(timeStampForKey[key].begin(), timeStampForKey[key].end(), timestamp) - begin(timeStampForKey[key]);
        idx--;

        cout<<idx<<endl;

        return mp[key][timeStampForKey[key][idx]];
        //return "";

    }
};
