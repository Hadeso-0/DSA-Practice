class Solution {
    // void solve(string& s, int idx, int mask, string& ans, string &temp){
    //     if(idx == s.size()){
    //         if(temp.size() > ans.size()) ans = temp;
    //         else if((temp.size() == ans.size()) && (temp < ans)) ans = temp;
    //         return;
    //     }

    //     int c = s[idx] - 'a';
    //     if(mask & (1<<c)){
    //         temp.push_back(s[idx]);
    //         solve(s, idx+1, mask^(1<<c), ans, temp);
    //         temp.pop_back();
    //     }
    //     solve(s, idx+1, mask, ans, temp);
    // }
public:
    string removeDuplicateLetters(string s) {
        // int mask = (1<<27)-1;
        // string ans = "";
        // string temp = "";
        // solve(s, 0, mask, ans, temp);
        // return ans;
        int n = s.size();
        unordered_map<char,int> frq; 
        unordered_map<char,bool> used;

        stack<int> st;
        for(int i=0; i<n; ++i){
            ++frq[s[i]];
            used[s[i]] = false;
        } 

        for(int i=0; i<n; ++i){
            --frq[s[i]];
            if(used[s[i]]) continue;

            while((!st.empty()) && (s[i] < s[st.top()]) && (frq[s[st.top()]] > 0)){
                used[s[st.top()]] = false; st.pop();
            }

            st.push(i); used[s[i]] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(s[st.top()]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};