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
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(auto x : nums) cout<<x<<" ";
        cout<<endl;
        for(int i=0; i<n; i++){
            if(2*nums[i] <= target) ans++;
            else break;
            int lb = upper_bound(nums.begin()+i+1, nums.end(), target-nums[i]) - nums.begin();          
            int x;
            if(lb == n){
                // possible for all
                x = (binPow(2, n-i-1)-1)%mod;
                cout<<i<<" possible for all combinations "<<x<<endl;
            }
            else{
                if(nums[i] + nums[lb] > target) lb--;
                if(i != lb)
                    x = (binPow(2,lb-i)-1)%mod;
                else
                    x = 0 ;
                cout<<i<<" "<<nums[i]<<" "<<nums[lb]<<" "<<x<<endl;
            }
            ans = (ans + x)%mod;
        }
        return ans;
    }
};