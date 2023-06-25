class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; ++i){
            int fd = nums[i]%10;
            while(nums[i]>=10) nums[i]/=10;
            int ld = nums[i];
            
            for(int x=1; x<=9; ++x){
                if(__gcd(x, fd) == 1){
                    ans += mp[x];
                }
            }
            ++mp[ld];
        }   
        return ans;
    }
};