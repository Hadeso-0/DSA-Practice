class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int i = 0;
        int j = n-1;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq_left;
        priority_queue<int, vector<int>, greater<int>> pq_right;
        
        for(int p=0; p<candidates; ++p){
            if(i > j) break;
            pq_left.push(costs[i]); ++i;
            if(i > j) break;
            pq_right.push(costs[j]); --j;
        }

        for(int p = 0; p<k; ++p){
            cout<<p<<" ";
            if(pq_left.empty()){ 
                ans+= pq_right.top(); pq_right.pop();
                if(i <= j){ pq_right.push(costs[j]); --j; } 
            }
            else if(pq_right.empty()){ 
                ans+= pq_left.top(); pq_left.pop();
                if(i <= j){ pq_left.push(costs[i]); ++i; } 
            }
            else if(pq_left.top() <= pq_right.top()){
                ans+= pq_left.top(); pq_left.pop();
                if(i <= j){ pq_left.push(costs[i]); ++i; } 
            }
            else{
                ans+= pq_right.top(); pq_right.pop();
                if(i <= j){ pq_right.push(costs[j]); --j; } 
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};