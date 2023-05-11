class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        unordered_map<int,int> row_map, col_map, dg1_map, dg2_map;        
        unordered_map<int,unordered_set<int>> on_map;        

        for(auto& l : lamps){
          if(on_map[l[0]].find(l[1]) == on_map[l[0]].end()){
            on_map[l[0]].insert(l[1]);
            ++row_map[l[0]];
            ++col_map[l[1]];
            ++dg1_map[l[0]+l[1]];
            ++dg2_map[l[0]-l[1]];
          }
        }
        
        vector<int> ans;
        vector<pair<int,int>> surr = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        long long r,c;
        for(auto& q : queries){
            if(row_map[q[0]]==0 && col_map[q[1]]==0 && 
                dg1_map[q[0]+q[1]]==0 && dg2_map[q[0]-q[1]]==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }

            // turn off the nine lamps
            for(int lamp=0; lamp<9; ++lamp){
                r = q[0] + surr[lamp].first;
                c = q[1] + surr[lamp].second;
                if(on_map[r].find(c) != on_map[r].end()){
                    on_map[r].erase(c);
                    --row_map[r];
                    --col_map[c];
                    --dg1_map[r+c];
                    --dg2_map[r-c];
                }
            }
        }
        return ans;
    }
};