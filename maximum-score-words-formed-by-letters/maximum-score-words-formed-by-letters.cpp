class Solution {
    int ans = 0;
    void solve(vector<string>& words, vector<int>& frq, int i, vector<int>& score, int cur_score){
        if(i == words.size()){
            ans = max(ans, cur_score);
            return;
        }
       
        solve(words, frq, i+1, score, cur_score);
        
        vector<int> temp = frq;
        int score_this = 0; bool canIncl = true;
        for(int j = 0; j<words[i].size(); ++j){
            if(temp[words[i][j]-'a'] == 0){
                canIncl = false;
                break;
            }
            else{
                --temp[words[i][j]-'a'];
                score_this += score[words[i][j]-'a'];
            }
        }
        if(canIncl){
            solve(words, temp, i+1, score, cur_score + score_this);
        }
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> frq(26,0); 
        for(int i=0;i<letters.size(); ++i) ++frq[letters[i]-'a'];
        solve(words, frq, 0, score, 0);
        return ans;
    }
};