class Solution {
    int init_size(int n, vector<vector<int>>& children, vector<int>& subTreeSize){
        if(children[n].size() == 0) return subTreeSize[n] = 1;
        int sz = 1;
        for(auto& ch : children[n]){
            sz += init_size(ch, children, subTreeSize);
        }
        return subTreeSize[n] = sz;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> children(n);
        for(int i=1; i<n; ++i){
            children[parents[i]].push_back(i);
        }

        vector<int> subTreeSize(n);
        init_size(0,children, subTreeSize);
        // for(int i=1; i<n; ++i){
        //     subTreeSize[parents[i]]    
        // }
        // for(auto& s : subTreeSize) cout<<s<<" ";
        // cout<<endl;
        unordered_map<long long,int> mp;
        
        long long ans = 0;
        for(int i=0; i<n; ++i){
            long long tmp = 1;
            for(auto& ch : children[i]){
                tmp = tmp*1LL*subTreeSize[ch];
            }
            if(parents[i] != -1){
                int par = min(parents[i], 0);
                tmp = tmp*1LL*(subTreeSize[par] - subTreeSize[i]);
            }
            // cout<<tmp<<" ";
            ans = max(ans, tmp);
            ++mp[tmp];
        }
        return mp[ans];
    }
};