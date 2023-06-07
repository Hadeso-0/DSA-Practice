class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int n = start^goal;
        while(n){
            ans += n%2;
            n/=2;
        }
        return ans;
    }
};