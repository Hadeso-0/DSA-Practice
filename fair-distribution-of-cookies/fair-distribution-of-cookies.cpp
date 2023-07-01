class Solution {
    void solve(int idx, vector<int>& ch, int& ans, vector<int>& cookies){
        if(idx == cookies.size()){
            int temp = *max_element(ch.begin(), ch.end());
            ans = min(ans, temp);
            return;
        }

        for(int i=0; i<ch.size(); ++i){
            // giving this bag's cookies to ith child
            // cout<<i<<" "<<cookies[idx]<<endl;
            ch[i] += cookies[idx];

            solve(idx+1, ch, ans, cookies);

            ch[i] -= cookies[idx];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> ch(k, 0);
        int ans = INT_MAX;

        solve(0, ch, ans, cookies);
        return ans;
    }
};