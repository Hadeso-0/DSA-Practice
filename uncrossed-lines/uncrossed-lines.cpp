class Solution {
    int findIdx(int target, vector<int>& nums, int s){
        for(int i=s; i<nums.size(); i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }
    
    int solve(int idx, vector<int>& nums1, vector<int>& nums2, int idx2, vector<vector<int>>& dp){
        if(idx >= nums1.size() || idx2 >= nums2.size()){
            return 0;
        }
        if(dp[idx][idx2] != -1) return dp[idx][idx2];

        // If i include this number in a connection
        int incl = 0;
        int idx2_new = findIdx(nums1[idx], nums2, idx2); 
        if(idx2_new != -1){ // its pair exist in nums2 after idx2
            incl = dp[idx+1][idx2_new+1];
            if(incl == -1)
                incl = solve(idx+1, nums1, nums2, idx2_new+1, dp); // idx2 is updated one
            
            ++incl;
        }

        // If I exclude this number in a connection or its pair does not exist
        int excl = dp[idx+1][idx2];
        if(excl == -1)
            excl = solve(idx+1, nums1, nums2, idx2, dp);

        return dp[idx][idx2] = max(incl, excl);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1,nums2);
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, -1));
        return solve(0,nums1, nums2, 0, dp);
    }
};