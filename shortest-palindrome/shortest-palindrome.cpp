class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0;
        string rev = s;
        reverse(rev.begin(), rev.end());

        string to_chk = s + "&" + rev;
        int n = to_chk.size();
        vector<int> lps(n, 0);

        for(int i=1; i<n; ++i){
            int j = lps[i-1];
            while((j > 0) && (to_chk[i] != to_chk[j])){
                j = lps[j-1];
            }

            if(to_chk[i] == to_chk[j]) ++j;
            lps[i] = j;
        }

        return rev + s.substr(lps[n-1]);
    }
};