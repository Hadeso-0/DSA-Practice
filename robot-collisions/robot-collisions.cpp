class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<pair<int,int>> going_right;
        stack<pair<int,int>> going_left;

        int n = positions.size();
        vector<int> ans;
        vector<vector<int>> robots;
        for(int i=0; i<n; ++i){
            vector<int> temp;
            temp.push_back(positions[i]);
            if(directions[i] == 'R') temp.push_back(1);
            else temp.push_back(2);
            temp.push_back(healths[i]);
            temp.push_back(i);

            robots.push_back(temp);
        }

        sort(robots.begin(), robots.end());
        // for(auto& i : robots){
        //     for(auto& j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int i = 0;
        while(i<n){
            while(i<n && robots[i][1] == 1){
                going_right.push({robots[i][2], robots[i][3]});
                ++i;
            }
            int j = i;
            while(j<n && robots[j][1] == 2){
                ++j;
            }
            int next_rnd = j; --j;
            while(j>=i){
                going_left.push({robots[j][2], robots[j][3]});
                --j;
            } 
            i = next_rnd;
            // cout<<going_left.size()<<" "<<going_right.size()<<endl;
            // Now These robots will interact with each other
            // interaction b/w going_right.top() & going_left.front()
            while(!going_right.empty() && !going_left.empty()){
                int robot1 = (going_right.top()).first; 
                int robot1_idx = (going_right.top()).second;
                going_right.pop();

                int robot2 = (going_left.top()).first; 
                int robot2_idx = (going_left.top()).second; 
                going_left.pop();

                // cout<<robot1<<" "<<robot2<<endl;
                if(robot1 == robot2){ 
                    // -> both robots will get destroyed
                    healths[robot1_idx] = 0;
                    healths[robot2_idx] = 0;
                }
                else if(robot1 > robot2){
                    // robot2 will be destroyed
                    // robot1's health reduced by 1
                    --healths[robot1_idx];
                    healths[robot2_idx] = 0;
                    // cout<<"r1 "<<healths[robot1_idx]<<" "<<robot1_idx<<endl;
                    if(healths[robot1_idx] > 0){
                        // cout<<"psh r1\n"; 
                        going_right.push({healths[robot1_idx], robot1_idx});
                    }
                }
                else{
                    // robot1 will be destroyed
                    // robot2's health reduced by 1
                    healths[robot1_idx] = 0;
                    --healths[robot2_idx];
                    cout<<"r2 "<<healths[robot2_idx]<<" "<<robot2_idx<<endl;
                    if(healths[robot2_idx] > 0){
                        // cout<<"psh r2\n"; 
                        going_left.push({healths[robot2_idx], robot2_idx});
                    }
                }
            }
            while(!going_left.empty()){
                healths[(going_left.top()).second] = (going_left.top()).first; 
                going_left.pop();
            }
        }
        while(!going_right.empty()){
            healths[(going_right.top()).second] = (going_right.top()).first; 
            going_right.pop();
        }

        for(auto& h : healths){
            if(h != 0) ans.push_back(h);
        }
        return ans;
    }
};