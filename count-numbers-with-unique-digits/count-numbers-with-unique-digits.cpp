class Solution {
    int solve(int n){
        int ans = 1; int poss = 9;
        for(int i = 1; i<=n; ++i){
            if(i == 1){ ans*=9; }
            else{ ans*= poss; --poss;}
        }
        return ans;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;

        int ans = 10;
        for(int i=2; i<=n; ++i){
            ans += solve(i);
        }
        return ans;
    }
};