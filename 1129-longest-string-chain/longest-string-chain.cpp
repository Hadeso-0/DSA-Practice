class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<string, int> mp;
        for(auto& word : words){
            mp[word] = 1;
        }

        sort(words.begin(), words.end(), [&](const string& a, const string& b){
            return a.size() > b.size();
        });
        
        int ans = 1;
        for(int i=0; i<words.size(); ++i){
            string w = words[i];
            // cout<<w<<" ";
            string prefix = "";
            string suffix = w.substr(1);
            
            if(mp.find(prefix + suffix) != mp.end()){
                mp[prefix + suffix] = max(mp[prefix + suffix], 1+mp[w]);
                ans = max(ans, mp[prefix + suffix]);
            }
            for(int j=0; j<(w.size()-1); ++j){
                prefix = prefix + w[j];
                suffix = suffix.substr(1);
                if(mp.find(prefix + suffix) != mp.end()){
                    mp[prefix + suffix] = max(mp[prefix + suffix], 1+mp[w]);
                    ans = max(ans, mp[prefix + suffix]);
                }
            }
        }
        // cout<<endl;
        // for(auto& it : mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        return ans;
    }
};