class Solution {
    // bool isPossible(int len, string&s , int k){

    // }
public:
    int characterReplacement(string s, int k) {
        
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = s.size();
        vector<int> frq(26,0);
        int max_frq;
        while(r < n){
            ++frq[s[r]-'A'];
            max_frq = *max_element(frq.begin(), frq.end());
            if((r-l+1 - max_frq) > k){
                while((r-l+1 - max_frq) > k){
                    --frq[s[l]-'A']; ++l;
                    max_frq = *max_element(frq.begin(), frq.end());
                }
            }
            ++r;
            ans = max(ans, r-l);
        }
        return ans;
    }
};