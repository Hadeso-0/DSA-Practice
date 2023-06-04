class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int index;
        int n = word2.size(), m =word1.size();
        if(n!=m) return false;
        vector<int> f1(26,0), f2(26,0);
        for(int i=0; i<n; i++) {
            f1[word1[i]-'a']++;
        }
        for(int i=0; i<n; i++) {
            index = word2[i]-'a';
            f2[index]++;
            if (f1[index]==0) return false;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        for(int i = 0; i < 26; ++i){
            if (f1[i] != f2[i]) return false;
        }
        return true;
    }
};