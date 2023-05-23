class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> ans;
        
        // for(int i=k; i <= nums.size(); ++i){
        //     int maxi = nums[i-k];
        //     for(int j=i-k+1; j < i; ++j){
        //         maxi = max(nums[j], maxi); 
        //     } 
        //     ans.push_back(maxi);
        // }
        // return ans;
        deque<int> dq;
        for(int i=0 ; i<k; ++i){
            if(dq.empty()) dq.push_back(i);
            else if(nums[dq.back()] >= nums[i]) dq.push_back(i);
            else{
                while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
                dq.push_back(i);
            }
        }
        vector<int> ans;
        ans.push_back(nums[dq.front()]);
        
        for(int i=k; i<nums.size(); ++i){
            while(!dq.empty() && dq.front() <= (i-k)) dq.pop_front();
            
            if(dq.empty()) dq.push_back(i);
            else if(nums[dq.back()] >= nums[i]) dq.push_back(i);
            else{
                while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
                dq.push_back(i);
            }
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};