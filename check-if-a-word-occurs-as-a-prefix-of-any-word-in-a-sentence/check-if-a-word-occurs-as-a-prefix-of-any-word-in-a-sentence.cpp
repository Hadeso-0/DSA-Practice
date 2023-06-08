class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();
        int i = 0;
        int j = 0;
        int words = 1;
        while(i<n){
            while(i<n && j<m){
                if(sentence[i] == ' ') break;
                if(sentence[i] == searchWord[j]){
                    ++j; ++i;
                    if(j==m) return words;
                }
                else{
                    break;
                }
            }
            while(i<n && sentence[i]!=' ') ++i;
            j = 0;
            ++words;
            ++i;
        }
        return -1;
    }
};