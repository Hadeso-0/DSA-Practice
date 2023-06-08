class DSU{
    vector<int> rank;
    vector<int> par;
    int find(int x){
        if(x == par[x]) return par[x];
        return par[x] = find(par[x]);
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;

        if(rank[x] < rank[y]){ par[x] = y; }
        else if(rank[x] > rank[y]){ par[y] = x; }
        else{
            ++rank[x]; par[y] = x;
        }
        return true;
    }
    public:
    DSU(int n){
        rank.resize(n+1, 0);
        par.resize(n+1, 0);
    }

    int getMSTweight(int n, vector<vector<int>>& ed, int e_focused, map<int,int>& edge_use, bool to_be_added){
        int MST_wt = 0;
        for(int i=0; i<=n; ++i){ 
            par[i] = i;
            rank[i] = 0;
        }
        if(to_be_added){
            for(int i=0; i<ed.size(); ++i){
                if(ed[i][3] == e_focused){
                    if(unite(ed[i][0], ed[i][1])){
                        MST_wt += ed[i][2];
                        ++edge_use[i];
                    }
                }
            }
        }
        for(int i=0; i<ed.size(); ++i){
            if(ed[i][3] == e_focused) continue;
            else{
                if(unite(ed[i][0], ed[i][1])){
                    MST_wt += ed[i][2];
                    ++edge_use[i];
                }
            }
        }
        int rt = find(0);
        for(int i=1; i<n; ++i) if(find(i) != rt) return 1e8;
        return MST_wt;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(2);
        DSU* g = new DSU(n);

        for(int i=0; i<edges.size(); ++i){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });

        map<int,int> edge_frq;
        int min_wt = g->getMSTweight(n, edges, -1, edge_frq, false);
        cout<<min_wt<<endl;

        for(int i=0; i<edges.size(); ++i){
            int wt_after_removing = g->getMSTweight(n, edges, i, edge_frq, false);
            int wt_if_added = g->getMSTweight(n, edges, i, edge_frq, true);
            // cout<<"wt aft removing"<<" "<<i<<" = "<<wt_after_removing<<","<<wt_if_added<<endl;
            if(wt_after_removing > min_wt){
                ans[0].push_back(i);
            }
            else if(wt_if_added == min_wt){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};