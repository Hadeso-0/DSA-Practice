class Solution {
    int dp[26][26][1005] = {};
    /**
     * @remark 
     * function = solve() returns integer(maximum number of characters that can be deleted)
     *            returns the maximum overlapping characters that can be acheived on merging
     *            strings
     *
     * params = first_char -> char at first index of str_idx-1
     *        = last_char -> char at end index of str_idx-1
     *        = idx -> index of the word under observation
     */
    int solve(char first_char, char last_char, int idx, vector<string>& words){

        if(idx == words.size()) return 0;
       
        // Memoization
        if(dp[first_char-'a'][last_char-'a'][idx] != -1) 
            return dp[first_char-'a'][last_char-'a'][idx];


        // If I take s_idx = s_idx-1 + words[idx];
        // and find maximum overlapping chars with currently formed 
        // string and words after this
        int way1 = solve( first_char, words[idx][words[idx].size()-1], idx+1, words);
        if(words[idx][0] == last_char){
            // Remove the last char of s_idx-1, if overlap
            ++way1; 
        }
        
        //  If I take s_idx = words[idx] + s_idx-1; 
        // and find maximum overlapping chars with currently formed 
        // string and words after this
        int way2 = solve( words[idx][0], last_char, idx+1, words);
        if(words[idx][words[idx].size()-1] == first_char){
            // Remove the first char of s_idx-1, if overlap
            ++way2;
        }     
        
        return dp[first_char-'a'][last_char-'a'][idx] = max(way1, way2);
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        
        // Take 1st word as str_0
        char first_char = words[0][0]; 
        char last_char = words[0][words[0].size()-1];

        // Reset dp
        memset(dp, -1, sizeof(dp));

        int n = words.size();
        int total_length = 0; // Maximum possible length
        for(int i=0; i<n; ++i){
            total_length += words[i].size();
        }
        
        // Minimum overlapping length = Total length - Maximum overlapping characters
        return total_length - solve( first_char, last_char, 1, words);
    }
};