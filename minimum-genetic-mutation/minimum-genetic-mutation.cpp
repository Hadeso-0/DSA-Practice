class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        unordered_map<string, int> bank_dict;
        for(int i=0; i<n; ++i){
            bank_dict[bank[i]] = i+1;
        }

        if(bank_dict.find(endGene) == bank_dict.end()) return -1;

        int des = bank_dict[endGene];

        vector<bool> vis(n+1);
        vector<char> mut = {'A', 'C', 'G', 'T'};
        queue<pair<int,int>> q;
        q.push({-1, 0});

        while(!q.empty()){

            int sz = q.size();
            for(int i=0; i<sz; ++i){
                int cur = q.front().first;
                int dis = q.front().second;
                q.pop();

                if(cur == des) return dis;
                string cur_s = (cur == -1) ? startGene : bank[cur-1]; 
                                
                for(int j=0; j<cur_s.size(); ++j){
                    char og = cur_s[j];
                    for(int k=0; k<4; ++k){
                        if(mut[k] == og) continue;
                        cur_s[j] = mut[k];
                        if(bank_dict[cur_s] != 0 && vis[bank_dict[cur_s]] == false){
                            q.push({bank_dict[cur_s], dis+1});
                            vis[bank_dict[cur_s]] = true;
                        }
                    }
                    cur_s[j] = og;
                }

            }
        }

        return -1;
        
    }
};