class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> q;
        for(int i=0; i<k; ++i){
            if(q.empty()) q.push_back(i);
            else if(nums[i] <= nums[q.back()]) q.push_back(i);
            else{
                while(!q.empty() && (nums[i] > nums[q.back()])) q.pop_back();
                q.push_back(i);
            }
        }

        vector<int> ans;
        ans.push_back(nums[q.front()]);
        for(int i=k; i<n; ++i){
            
            while(!q.empty() && (q.front() <= i-k)){
                q.pop_front();
            }
            
            if(q.empty()) q.push_back(i);
            else if(nums[i] <= nums[q.back()]) q.push_back(i);
            else{
                while(!q.empty() && (nums[i] > nums[q.back()])) q.pop_back();
                q.push_back(i);
            }

            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};