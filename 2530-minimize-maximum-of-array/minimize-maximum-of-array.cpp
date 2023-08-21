class Solution {
    bool isValid(vector<int>& arr, long long x){
        long long preS = 0;
        for(long long i=0; i<arr.size(); ++i){
            preS += arr[i]*1LL;
            if(preS > x*1LL*(i+1)) return false;
        }
        return true;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        // long long ans = 0;
        // long long pref = 0;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     pref += nums[i]*1ll;
        //     ans =  max(ans, (pref+i)/(i+1));
        // }
        // return ans;
        long long l = 0;
        long long r = *max_element(nums.begin(), nums.end()) * 1LL;
        long long ans = r;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(isValid(nums, mid)){
                ans = mid;
                r = mid-1; 
            }
            else{
                l = mid+1;
            }
        } 
        return ans;

    }
};