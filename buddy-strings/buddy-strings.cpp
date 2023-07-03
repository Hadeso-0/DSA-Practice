class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int cnt = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] != goal[i]) ++cnt;
        }
        if(cnt == 0){
            vector<int> chrs(26,0);
            for(int i=0; i<s.size(); ++i){
                if(chrs[s[i]-'a']) return true;
                ++chrs[s[i]-'a'];
            }
            return false;
        }
        if(cnt == 2){
            int dif = -1;
            for(int i=0; i<s.size(); ++i){
                if(s[i] != goal[i]){
                    if(dif == -1){ dif = i; }
                    else{
                        if(s[i] == goal[dif] && s[dif] == goal[i]) 
                            return true;
                        
                        return false;
                    }
                }
            }
            return false;  
        }
        return false;

    }
};