class DSU{
  public:
    int nodes;
    vector<int> par;
    vector<int> rank;
    
    DSU(int n){
        nodes = n;
        par.push_back(0);
        rank.push_back(0);
        for(int i=1; i<=n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int findPar(int x){
        if(x==par[x]){
            return x;
        }
        return par[x] = findPar(par[x]);
    }
    int unionByRank(int x, int y){
        x = findPar(x);
        y = findPar(y);

        if(x==y) return 1;

        if(rank[x] > rank[y]){
            par[y] = x;
        } else if(rank[x] < rank[y]){
            par[x] = y;
        } else{
            par[x] = y;
            rank[x]++;
        }
        return 0;
    }
    bool checkFullyConnected(){
        int roots = 0;
        for(int i=1; i<=nodes; i++){
            if(i == par[i]) roots++;
        }
        return roots==1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU *graphA = new DSU(n);
        DSU *graphB = new DSU(n);

        unordered_map<int, vector<vector<int>>> edgeMap;
        for(auto ed : edges){
            edgeMap[ed[0]].push_back({ed[1],ed[2]});
        }
        int ans = 0;

        for(auto ed : edgeMap[3]){
            ans += min(1, graphA->unionByRank(ed[0],ed[1]) + graphB->unionByRank(ed[0],ed[1]));
        }
        for(auto ed : edgeMap[2]){
            ans += graphB->unionByRank(ed[0],ed[1]);
        }
        for(auto ed : edgeMap[1]){
            ans += graphA->unionByRank(ed[0],ed[1]);
        }

        if(graphA->checkFullyConnected() && graphB->checkFullyConnected())
            return ans;
        else
            return -1;
    }
};