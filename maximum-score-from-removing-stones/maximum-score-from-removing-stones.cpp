class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a); pq.push(b); pq.push(c);

        int ans = 0;
        while(pq.size() > 1){
            int p1 = pq.top(); pq.pop(); --p1;
            int p2 = pq.top(); pq.pop(); --p2;
            ++ans;
            if(p1 != 0) pq.push(p1);
            if(p2 != 0) pq.push(p2);
        }
        return ans;
    }
};