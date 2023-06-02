class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vows;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vows.push_back(s[i]);
            }
        }
        reverse(vows.begin(), vows.end());
        int j = 0; int i= 0;
        while(i<s.size() && j<vows.size()){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i] = vows[j];
                ++j;
            }
            ++i;
        }
        return s;
    }
};