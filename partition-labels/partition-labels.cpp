class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> mp(26, -1);

        for(int i=0; i<s.size(); ++i){
            mp[s[i]-'a'] = i;
        }

        int this_part = 0;
        int strt = 0;
        for(int i=0; i<s.size(); ++i){
            this_part = max(this_part, mp[s[i]-'a']);
            if(i == this_part){
               ans.push_back(i-strt+1);
               strt = i+1;
            }
        }
        
        return ans;
    }
};