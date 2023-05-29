class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int r = 0;
        int c = 0;
        bool d = 0;
        vector<int> ans;
        while(r < n && c < m){
            ans.push_back(mat[r][c]);
            int nex_r = r + (d==0 ? -1: 1);
            int nex_c = c + (d==1 ? -1: 1);

            // check if nex_r & nex_c are in bound
            if(nex_r <0 || nex_c<0 || nex_r == n || nex_c == m){
                if(d == 0){
                    if(c == m-1) ++r;
                    else ++c;
                }
                else{
                    if(r == n-1) ++c;
                    else ++r;
                }
                d = 1-d;
            }
            else{
                r = nex_r;
                c = nex_c;
            }
        }
        return ans;
    }
};