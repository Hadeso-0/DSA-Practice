class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        vector<long long> extra1, extra2;
        map<long long, long long> frq, frq1, frq2;
        for(auto& i : basket1){
            ++frq[i]; ++frq1[i];
        }
        for(auto& i : basket2){
            ++frq[i]; ++frq2[i];
        }

        long long min_el = LONG_MAX;
        for(auto& i : frq){
            if(i.second&1) return -1LL;
            min_el = min(min_el, i.first);
            
            int tot = (i.second/2);
            int need1 = frq1[i.first] - tot;
            int need2 = frq2[i.first] - tot;
            
            for(int j=0; j<need1; ++j) extra1.push_back(i.first);
            for(int j=0; j<need2; ++j) extra2.push_back(i.first);
        }

        reverse(extra2.begin(), extra2.end());
        long long ans = LONG_MAX;
        long long cost = 0;
        long long min_cost = 2LL*min_el;

        for(int i=0; i<extra1.size(); ++i){
            long long cur_cost = min(extra1[i], extra2[i]);
            cost += min(cur_cost, min_cost);
        }

        ans = min(ans, cost);
        return ans;
    }
};