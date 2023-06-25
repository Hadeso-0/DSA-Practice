class Solution {
    int dp[26][26][1005] = {};
    int solve(char fc, char lc, int idx, vector<string>& words){

        // cout<<idx<<" "<<fc<<" "<<lc<<endl;
        int pos1=0,pos2=0, pos3 = 0;
        if(idx == words.size()) return 0;
        if(dp[fc-'a'][lc-'a'][idx] != -1) return dp[fc-'a'][lc-'a'][idx];

        pos1 = solve( fc, words[idx][words[idx].size()-1], idx+1, words);
        if(words[idx][0] == lc){
            ++pos1; 
        }
        
        pos2 = solve( words[idx][0], lc, idx+1, words);
        if(words[idx][words[idx].size()-1] == fc){
            ++pos2;
        }     
        
        return dp[fc-'a'][lc-'a'][idx] = max(pos1, pos2);
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        char fc = words[0][0]; char lc = words[0][words[0].size()-1];
        memset(dp, -1, sizeof(dp));

        int n = words.size();
        int len = 0;
        for(int i=0; i<words.size(); ++i){
            len += words[i].size();
        }
        
        return len-solve( fc, lc, 1, words);
    }
};