class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto n : nums){
            mp[n]++;
        }   
        priority_queue<pair<int,int>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            if(!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};