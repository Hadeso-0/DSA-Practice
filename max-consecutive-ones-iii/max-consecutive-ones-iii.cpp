class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int last_zero = -1;
        
        queue<int> log_zeros;
        log_zeros.push(-1);
        int i;
        for(i=0; i<nums.size(); ++i){
            if(nums[i] == 0){
                if(k == 0){ 
                    last_zero = log_zeros.front(); log_zeros.pop();
                    ans= max(ans, i-last_zero-1);
                    cout<<last_zero<<"-"<<i-1<<" "<<ans<<endl;
                }
                else --k;
                log_zeros.push(i);
            }
        }
        last_zero = log_zeros.front(); log_zeros.pop();
        ans= max(ans, i-last_zero-1);
        cout<<last_zero<<"-"<<i-1<<" "<<ans<<endl;
        return ans;
    }
};