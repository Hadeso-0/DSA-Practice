class Solution {
    bool compare(vector<int>& a, vector<int>& b){
        return ((a[0]<b[0])&&(a[1]<b[1]));
    }
    int find_inner(vector<vector<int>>& arr, int i){
        // find rightmost envelope that can be put inside cur
        int l = 0;
        int r = i-1;
        int ans = -1;
        int mid = l + (r-l)/2;
        while(l<=r){
            mid = l + (r-l)/2;
            if(compare(arr[mid], arr[i])){
                l = mid+1;
                ans = mid;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] < b[0]) return true;
            else if(a[0] == b[0]) return a[1] > b[1];
            return false;
        });
        int n = envelopes.size();
        vector<int> ans;
        for(int i=0; i<n; ++i){
            auto it = lower_bound(ans.begin(), ans.end(), envelopes[i][1]);
            if(it == ans.end()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                *it = envelopes[i][1];
            }
        }
        return ans.size();
    }
};