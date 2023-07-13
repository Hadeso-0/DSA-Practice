class Solution {
    int ans = INT_MAX;
    void solve(int i, int k, int n, vector<int>&jobs, vector<int> worker){
        if(i == n){
            int temp = *max_element(worker.begin(),worker.end());
            ans = min(ans,temp);
            return;
        }

        if(*max_element(worker.begin(),worker.end()) >= ans) return;

        for(int j = 0; j < k; j++){
            if((j > 0) && (worker[j] >= worker[j - 1]))continue;
            worker[j] += jobs[i];
            solve( i+1, k, n, jobs, worker);
            worker[j] -= jobs[i];
        }
        return ;
    }

    public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(),jobs.end(),greater<int>());
        
        int n = jobs.size();
        if(n == k)return jobs[0];
        
        vector<int> worker(k, 0);
        solve( 0, k, n, jobs, worker);
        return ans;
    }
};