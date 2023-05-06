class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto i : nums){
            if(mp[i]) return true;
            mp[i] = 1;
        }
        return false;
    }
};