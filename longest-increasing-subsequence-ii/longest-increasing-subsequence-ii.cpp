class Solution {
    const int N = 100002;
    vector<int> tree;
    void update(int tar, int val, int idx, int low, int high){
        if(low > high) return;
        if(low > tar || tar > high) return;
        if(low == high){
            tree[idx] = val;
            return;
        }

        int mid = low + (high-low)/2;
        if(tar<=mid  && tar >= low){
            update(tar, val, 2*idx+1, low, mid);
        }
        else{
            update(tar, val, 2*idx+2, mid+1, high);
        }
        tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
    }
    int query(int l, int r, int idx, int low, int high){
        if(low > high) return INT_MIN;
        if(low > r || l > high) return INT_MIN;
        if((l <= low) && (high <= r)){
            return tree[idx];
        }

        int mid = low + (high-low)/2;
        int lft = query(l, r, 2*idx+1, low, mid);
        int rgt = query(l, r, 2*idx+2, mid+1, high);
        return max(lft, rgt);
    }

public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        tree.resize(4*N, 0);
        int ans = 0;
        for(int i=0; i<n; ++i){
            // find the LIS ending in [nums[i]-k ... nums[i]-1]
            int q = query(max(nums[i]-k, 0), nums[i]-1, 0, 0, N);
            ans = max(ans, q+1);
            update(nums[i], q+1, 0, 0, N);
        }
        return ans;
    }
};