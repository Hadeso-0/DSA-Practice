class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cst(n, 0);   
        for(int i=0; i<n; ++i){
            cst[i] = abs(s[i]-t[i]);
        }

        for(auto& c: cst) cout<<c<<" ";
        int ans =0;
        int l = 0; int r = 0;
        int curCost = 0;
        while(r < n){
            curCost += cst[r];
            if(curCost > maxCost){
                while(l <= r && curCost > maxCost){
                    curCost -= cst[l];
                    ++l;
                }
            }
            ++r;
            ans = max(ans, r-l);
        }
        return ans;
    }
};