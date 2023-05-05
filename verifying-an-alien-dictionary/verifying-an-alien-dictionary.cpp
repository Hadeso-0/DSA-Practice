class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> char_to_ind;
        for(int iterator=0; iterator<order.size(); iterator++){
            char_to_ind[order[iterator]] = iterator;
        }

        for(int i=1; i<words.size(); i++){
            for(int j = 0; j<words[i-1].size(); j++){
                if( j >= words[i].size()){
                    return false;
                }

                if(words[i-1][j] != words[i][j]){
                    if(char_to_ind[words[i-1][j]] > char_to_ind[words[i][j]]){
                        return false;
                    }
                    // if words are not equal and are sorted -> strings are sorted
                    else break;
                }
            }
        }
        return true;
    }
};