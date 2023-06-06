class Solution {
    bool isAP(vector<int> nums, int l, int r){
        int n = r-l+1;
        if(n < 3) return true;

        sort(nums.begin()+l, nums.begin()+r+1);
        // for(auto&x : nums) cout<<x<<" ";
        // cout<<endl;
        int d = nums[l+1] - nums[l];
        for(int i=2; i<n; ++i){
            if(nums[l+i] - nums[l+i-1] != d) return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); ++i){
            ans.push_back(isAP(nums, l[i], r[i]));
        }
        return ans;
    }
};