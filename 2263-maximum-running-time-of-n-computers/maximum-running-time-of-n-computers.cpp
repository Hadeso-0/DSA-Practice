class Solution {
    bool isPossible(int n, int m, vector<int>& bat, long long target){
        long long tot_energy = 0LL;

        for(int i=0; i<m; ++i){
            tot_energy = tot_energy + min(bat[i]*1LL, target);
        }

        return tot_energy >= n*target;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0LL;
        int m = batteries.size();
        for(int i=0; i<m; ++i){
            sum += batteries[i];
        }

        long long l = 0LL;
        long long r = sum/(long)n;
        long long ans = -1;

        while(l <= r){
            long long mid = l + (r-l)/2LL;

            if(isPossible(n, m, batteries, mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};