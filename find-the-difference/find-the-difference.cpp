class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0;
        while(i<s.size() && s[i]==t[i]){
            i++;
        }
        return t[i];
    }
};