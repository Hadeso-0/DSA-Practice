class Solution {
    vector<long long> facts;
    void getFact(){
        facts.resize(10, 1);
        for(int i=2; i<10; ++i){
            facts[i] = facts[i-1]*i;
        }
    }

    string solve(int n, int k, set<string>& st){
        if(n == 1){
            return *st.begin();
        }
        int fst = (k / facts[n-1]);
        auto fs = st.begin();
        for(int i=0; i<fst; ++i) ++fs;
        string ans = *fs;
        st.erase(*fs);
        int k_new = (k % facts[n-1]);
        ans += solve(n-1, k_new, st);
        return ans;
    }

public:
    string getPermutation(int n, int k) {
        getFact();
        set<string> st;
        for(int i=1; i<=n; ++i) st.insert(to_string(i));
        --k;
        return solve(n , k, st);
        // --k;
        // return solve(1,1,st);
    }
};