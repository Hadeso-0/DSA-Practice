class Solution {
    void solve(int idx, int cnt, vector<vector<int>>& requests, vector<int>& degree, int& ans){
        if(idx == requests.size()){
            // Check if this is a possible config
            // bool flg = true;
            for(auto& i : degree){
                // cout<<i<<" ";
                if(i != 0) {
                    // flg = false;
                    return;
                }
            }
            // cout<<" -> "<<cnt<<endl;
            // if(flg) 
            ans = max(ans,cnt);
            return;
        }

        // If i consider request[idx]
        degree[requests[idx][0]]--;
        degree[requests[idx][1]]++;
        solve(idx+1, cnt+1, requests, degree, ans);
        
        degree[requests[idx][0]]++;
        degree[requests[idx][1]]--;

        // If i do not consider request[idx]
        solve(idx+1, cnt, requests, degree, ans);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> degree(n, 0);
        solve(0, 0, requests, degree, ans);
        return ans;
    }
};