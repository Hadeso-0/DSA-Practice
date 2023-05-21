class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s += " ";
        string cur = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(cur.size() > 0)
                    st.push(cur);
                cur = "";
            }
            else{
                cur.push_back(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};