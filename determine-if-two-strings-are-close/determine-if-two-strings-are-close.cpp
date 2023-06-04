class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;   
        vector<int> frq1(26,0);
        vector<int> frq2(26,0);
        for(int i=0; i<word1.size(); ++i){
            ++frq1[word1[i]-'a'];
            ++frq2[word2[i]-'a'];
        }
        for(int i=0; i<26; ++i){
            if((frq1[i]!=0 && frq2[i]==0) || (frq1[i]==0 && frq2[i]!=0)) return false;
        }
        unordered_map<int,int> mp;
        for(int i=0; i<26; ++i){
            ++mp[frq1[i]];
            --mp[frq2[i]];
        }
        for(auto& x : mp) if(x.second != 0) return false;
        return true;
    }
};