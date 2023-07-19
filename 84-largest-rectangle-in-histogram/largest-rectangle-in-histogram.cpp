class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i=0; i<=n; ++i){
            while(!st.empty() && ((i == n) || (heights[st.top()] >= heights[i]))){
                int ht = heights[st.top()]; st.pop();
                int wd = 1;
                if(st.empty()){
                    wd = i;
                }
                else{
                    wd = i - st.top() - 1;
                }
                ans = max(ans, ht*wd);
            }
            st.push(i);
        }   
        return ans;
    }
};