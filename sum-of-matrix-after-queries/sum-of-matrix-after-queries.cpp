class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        for(int q = queries.size()-1; q>=0; --q){
            if(rows.size() == n && cols.size() == n) break;
            if(queries[q][0] == 0){
                if(rows.find(queries[q][1]) == rows.end()){
                    ans += (n-cols.size())*queries[q][2];
                    rows[queries[q][1]] = queries[q][2];
                }
            }
            else{
                if(cols.find(queries[q][1]) == cols.end()){ 
                    ans += (n-rows.size())*queries[q][2];
                    cols[queries[q][1]] = queries[q][2];
                }
            }
        }
        return ans;
    }
};