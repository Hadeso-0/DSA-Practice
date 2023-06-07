class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        // cout<<(start & (1<<1))<<endl;
        for(int i=0; i<32; ++i){
            int bit_a = 0; int bit_b = 0;
            if((start & (1<<i)) != 0) bit_a = 1;
            if((goal & (1<<i))  != 0) bit_b = 1;
            // cout<<bit_a<<" "<<bit_b<<" "<<(1<<i)<<endl;
            ans += (bit_a ^ bit_b);
        }
        return ans;

    }
};