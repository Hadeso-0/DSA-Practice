class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int> temp;
        temp.push_back(obs[0]);
        vector<int> ans = {1};

        for(int i=1; i<obs.size(); i++){
            if(obs[i] >= temp.back()){
                temp.push_back(obs[i]);
                ans.push_back(temp.size());
            }
            else{
                int ub = upper_bound(temp.begin(), temp.end(), obs[i])-temp.begin();
                temp[ub] = obs[i];
                ans.push_back(ub+1);
            }
        }
        return ans;
    }
};