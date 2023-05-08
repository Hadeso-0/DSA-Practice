class Solution {
    int mod = 1e9+7;
public:
    int numWays(string s) {
        long long n = s.size();
        long long int cur = 0;
        long long int nex = 0;
        unordered_map<long long int, long long int> mp;
        for(long long i=0; i<n; i++){
            nex = cur + (s[i]-'0');
            mp[nex] = (mp[nex] + 1)%mod;
            cur = nex;
        }  
        if(cur % 3 != 0) return 0;
        if(cur == 0) return ((1ll*(n-1)*(n-2))/2)%mod;

        return (1ll*mp[cur/3]*mp[2*cur/3]%mod);
    }
};