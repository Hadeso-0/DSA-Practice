class Solution {
    const vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        for(int i=0; i<words.size(); ++i){
            string tmp = "";
            for(int j=0; j<words[i].size(); ++j){
                tmp += morse[words[i][j]-'a'];
            }
            st.insert(tmp);

            cout<<tmp<<endl;
        }
        return st.size();
    }
};