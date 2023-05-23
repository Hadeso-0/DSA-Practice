class Solution {
public:
    string minWindow(string s, string t) {
        int i,j,k;
        int n = s.size();
        string ans = "#"+s;
        unordered_map<char,int> mp;
        for(int p=0; p<t.size(); ++p) ++mp[t[p]];
        int cnt = mp.size();

        i = 0;
        j = 0;

        while(i < n && j<n){
            // cout<<i<<" "<<j<<"  . ";
            while((j < n) && (cnt > 0)){
                if(mp.find(s[j]) != mp.end()){
                    if(--mp[s[j]] == 0) --cnt;
                }
                ++j;
            }
            if(cnt > 0) continue;

            while(i <= j){
                if(mp.find(s[i]) != mp.end()){
                    if(mp[s[i]] == 0){ 
                        ++mp[s[i]];
                        ++cnt;
                        break;
                    }
                    else ++mp[s[i]];
                }
                ++i;
            }
            if(j-i < ans.size()){
                ans = s.substr(i, j-i);
                cout<<i<<" "<<j<<" "<<ans<<endl;
            }
            ++i;
        }
        if(ans[0] == '#') return "";
        return ans;
    }
};