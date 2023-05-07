class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        queue<int> q;
        for(auto n : nums){
            q.push(n);
        }

        int a,b;
        bool flg = true;
        while(q.size() >= 2){
            a = q.front(); q.pop();
            b = q.front(); q.pop();
            if(flg)
                q.push(min(a,b));
            else
                q.push(max(a,b));
            flg = !flg;
        }

        return q.front();
    }
};