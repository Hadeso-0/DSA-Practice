class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        int cur = 0;
        int j = -1;
        for(int i=0; i<n; i++){
            if(s[i] == '(') cur++;
            else if(s[i] == ')') cur--;

            if(cur < 0){ 
                cur = 0;
                j  = i;
            }
            else if(cur == 0){
                ans = max(ans, i-j);
            }
        }
        
        j = n;
        cur = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') cur++;
            else if(s[i] == ')') cur--;

            if(cur > 0){ 
                cur = 0;
                j  = i;
            }
            else if(cur == 0){
                ans = max(ans, j-i);
            }
        }
        return ans;
    }
};