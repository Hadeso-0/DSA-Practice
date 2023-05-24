class Solution {
    static bool comp(pair<int,int>& a, pair<int,int>& b){
        if(a.second > b.second) return true;
        else if(a.second < b.second) return false;
        else if(a.first > b.first) return true;
        else return false;
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> nums;
        for(int i=0; i<nums1.size(); ++i){
            nums.push_back({nums1[i], nums2[i]});
        }
        sort(nums.begin(), nums.end(), comp);

        for(int i=0; i<nums.size(); ++i){
            cout<<nums[i].first<<" "<<nums[i].second<<endl;
        }
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long max_sm = 0;
        for(int i=0; i<k; ++i){
            minHeap.push(nums[i].first);
            max_sm += nums[i].first;
        }

        long long ans = max_sm * nums[k-1].second;
        for(int i=k; i<nums.size(); ++i){
            max_sm -= minHeap.top();
            minHeap.pop();
            max_sm += nums[i].first;
            minHeap.push(nums[i].first);

            ans = max(ans, max_sm*nums[i].second);
        }
        return ans;
    }
};