class Solution {
    bool comp(const vector<int>& a, const vector<int>& b){
        return (a[0]*1LL*a[0] + a[1]*1LL*a[1]) < (b[0]*1LL*b[0] + b[1]*1LL*b[1]);
    }
    long long dis(const vector<int>& a){
        return (a[0]*1LL*a[0] + a[1]*1LL*a[1]);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,int>> pq;
        int n = points.size();
        for(int i=0; i<n; ++i){
            if(pq.size() < k){
                pq.push({dis(points[i]),i});
            }
            else{
                if(comp(points[i], points[(pq.top()).second])){
                    cout<<i<<" ";
                    pq.pop();
                    pq.push({dis(points[i]), i});
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){ 
            ans.push_back(points[(pq.top()).second]);
            pq.pop();
        }
        return ans;


        // sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
        //     return (a[0]*1LL*a[0] + a[1]*1LL*a[1]) < (b[0]*1LL*b[0] + b[1]*1LL*b[1]);
        // });
        // int n = points.size();
        // vector<vector<int>> ans;
        // for(int i=0; i<min(n,k); ++i) ans.push_back(points[i]);
        // return ans;
    }
};