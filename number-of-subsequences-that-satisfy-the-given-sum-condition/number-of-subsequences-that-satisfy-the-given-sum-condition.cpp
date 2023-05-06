class Solution {
    int mod = 1e9+7;
    long long binPow(int x, int p){
        if(p==0) return 1;
        if(p==1 || x==1) return x;
        int pw = binPow(x,p/2)%mod;
        
        if(p%2) return (x*(pw*(pw*1ll)%mod)%mod)%mod;
        else return (pw*(pw*1ll)%mod)%mod;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        
        vector<int> preCompPow = {1};
        for(int i=1; i<=n; i++){
            preCompPow.push_back(binPow(2, i)%mod);
        }

        int l = 0; int r = n-1;
        while(l<=r){
            if(nums[l] + nums[r] > target) r--;
            else{    
                ans = (ans + preCompPow[r-l])%mod;
                l++;
            }
        }
        return ans;
    }
};