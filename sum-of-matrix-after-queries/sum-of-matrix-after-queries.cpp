class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        vector<unordered_set<int>> mark(2);
        
        for(int q = queries.size()-1; q>=0; --q){
            if(mark[0].size() == n && mark[1].size() == n) break;
            if(mark[queries[q][0]].find(queries[q][1]) == mark[queries[q][0]].end()){
                ans += (n-mark[1 - queries[q][0]].size())*queries[q][2];
                mark[queries[q][0]].insert(queries[q][1]);
            }
        }
        return ans;
    }
};