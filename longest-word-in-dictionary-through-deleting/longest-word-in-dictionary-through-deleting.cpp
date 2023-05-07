class Solution {
    bool lcs(string& s, string& target){
        int n = s.size();
        int m = target.size();
        int i,j;
        for(i=0, j=0; i<n && j<m; ){
            if(s[i] == target[j]){
                j++;
            }
            i++;
        }
        return j == m;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        string ans = "";
        for(auto word : dictionary){
            if(((ans.size() < word.size()) || (ans.size() == word.size() && ans.compare(word) > 0)) && lcs(s, word)){
                ans = word;
            }
        }
        return ans;
    }
};