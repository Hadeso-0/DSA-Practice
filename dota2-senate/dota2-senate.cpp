class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q1,q2;
        for(int i=0; i<n; i++){
            if(senate[i] == 'R') q1.push(i);
            else q2.push(i);
        }

        while(!q1.empty() && !q2.empty()){
            int q1_per = q1.front(); q1.pop();
            int q2_per = q2.front(); q2.pop();
            if(q1_per < q2_per){
                q1.push(q1_per+n);
            }
            else{
                q2.push(q2_per+n);
            }
        }

        if(q1.empty()) return "Dire";
        else return "Radiant";
    }
};