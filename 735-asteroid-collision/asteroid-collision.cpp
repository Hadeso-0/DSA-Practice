class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); ++i){
            bool flg = true;
            while(!st.empty() && asteroids[i]<0 && st.top() > 0){
                if(st.top() < -asteroids[i]){
                    st.pop();
                }
                else{ 
                    if(st.top() == -asteroids[i]){
                        st.pop();
                    }
                    flg = false;
                    break;
                }
            }
            if(flg) st.push(asteroids[i]);
        }   
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};