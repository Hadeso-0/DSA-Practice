class Solution {
    vector<int> par;
    vector<int> rank;
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;

        if(rank[x] > rank[y]) par[y] = x; 
        else if(rank[x] < rank[y]) par[x] = y;
        else{
            par[x] = y;
            ++rank[y];
        } 
        return true;
    }
    int dist(vector<int>& a, vector<int>& b){
        return (abs(a[0]-b[0]) + abs(a[1]-b[1]));
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        par.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0; i<n; ++i) par[i] = i;
    

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> connects;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                connects.push({dist(points[i],points[j]),i,j});
            }
        }
        int lines = 0;
        int ans = 0;
        while(lines < n-1 && !connects.empty()){
            vector<int> tp = connects.top(); connects.pop();
            if(unite(tp[1], tp[2])){ ans += tp[0]; ++lines;}
        }
        int rt = find(0);
        for(int i=1; i<n; ++i){
            if(find(i) != rt) return INT_MAX;
        }
        return ans;
    }
};