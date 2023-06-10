class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans =0;
        int l = 0; int r = 0;
        int curCost = 0;
        while(r < n){
            curCost += abs(s[r]-t[r]);
            if(curCost > maxCost){
                while(l <= r && curCost > maxCost){
                    curCost -= abs(s[l]-t[l]);
                    ++l;
                }
            }
            ++r;
            ans = max(ans, r-l);
        }
        return ans;
    }
};