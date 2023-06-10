class Solution {
    vector<int> pre;
public:
    Solution(vector<int>& w) {
        pre.resize(w.size());
        pre[0] = w[0];
        for(int i=1; i<w.size(); ++i){
            pre[i] = pre[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int randWt = rand()%pre[pre.size()-1];
        return upper_bound(pre.begin(), pre.end(),randWt) - pre.begin();
        // return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */