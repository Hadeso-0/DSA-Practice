class Solution {
    bool isPossible(vector<int>& nums, int n, int max_diff, int req){
        int cnt = 0;
        int i = 0;
        // cout<<max_diff<<"-> ";
        while(i<(n-1)){
            if((nums[i+1] - nums[i]) <= max_diff){
                // cout<<i<<" "<<i+1<<", ";
                ++cnt;
                i += 2;
            }
            else{
                i += 1;
            }
        }
        // cout<<endl;
        return (cnt >= req);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0;
        int hi = nums[n-1]-nums[0];
        int ans = hi;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(nums, n, mid, p)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        return ans;
    }
};