class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int sps = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ') sps++;
            if(sps == k) break;
            ans += s[i];
        }
        return ans;
    }
};