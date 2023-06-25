class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        for(auto s : words){
            if(mp.find(s) != mp.end()){ 
                ++ans;
                --mp[s];
                if(mp[s] == 0) mp.erase(s);
            }
            reverse(s.begin(), s.end());
            ++mp[s];
        }
        return ans;
    }
};