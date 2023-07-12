class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<pair<int,int>> pq;
        pq.push({nums[n-1], -(n-1)});
        int ans = nums[n-1];

        for(int i=n-2; i>=0; --i){
            while(!pq.empty() && (-(pq.top().second) > i+k)) pq.pop();
            ans = nums[i] + pq.top().first;

            pq.push({ans, -i});
        }

        return ans;
    }
};