class Solution {
    
    void solve(int idx, vector<int>& workers , int& ans, vector<int>& jobs){
        if(idx == jobs.size()){
            int temp = *max_element(workers.begin(), workers.end());
            ans = min(ans, temp);
            return;
        }
        set<int> seen;
        for(int i=0; i<workers.size(); ++i){
            // giving this bag's cookies to ith child
            // cout<<i<<" "<<cookies[idx]<<endl;
            if(seen.find(workers[i]) != seen.end()) continue;
            if(workers[i] + jobs[idx] >= ans) continue;
            
            seen.insert(workers[i]);

            workers[i] += jobs[idx];
            solve(idx+1, workers, ans, jobs);
            workers[i] -= jobs[idx];
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        
        if (k == jobs.size()) return *max_element(begin(jobs), end(jobs));       
        
        vector<int> workers(k, 0);
        int ans = INT_MAX;
        
        sort(jobs.begin(), jobs.end());
        solve(0, workers, ans, jobs);
        return ans;
    }
};