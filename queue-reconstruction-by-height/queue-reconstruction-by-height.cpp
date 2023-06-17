class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // vector<vector<int>> ans;   
        // sort(people.begin(), people.end(), [&](const vector<int>& a, const vector<int>& b){
        //     return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        // });

        // for(auto& p : people){
        //     ans.insert(ans.begin()+p[1] , p);
        // }

        // return ans;

        // Logic -> I insert the ith starting from smallest person to tallest one such that
        // There exist p[i][1] empty spots before him to be filled by taller people

        // O(n^2)
        vector<vector<int>> ans(people.size());
        vector<bool> empt(people.size(), true);

        sort(people.begin(), people.end(), [&](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        for(auto& p : people){
            int ht = p[0];
            int empty_before = p[1];

            int pos = 0;
            for(; pos<empt.size(); ++pos){
                if(empt[pos] && (empty_before == 0)){
                    break;
                }
                if(empt[pos]){ --empty_before; }
            }

            if(pos >= empt.size()) return {};
            ans[pos] = p;
            empt[pos] = false;
        }
        return ans;
    }
};