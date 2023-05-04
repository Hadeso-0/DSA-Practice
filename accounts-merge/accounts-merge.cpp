class Solution {
  vector<int> group;
  vector<int> rank;

  int findGroup(int x){
    if(x == group[x]) return x;
    return group[x] = findGroup(group[x]);
  }

  void unionGroups(int x, int y){
    x = findGroup(x);
    y = findGroup(y);

    if(x==y) return;
    if(rank[x] < rank[y]){
        group[x] = y;
    }else if(rank[x] > rank[y]){
        group[y] = x;
    }else{
        rank[x]++;
        group[y] = x;
    }
  }

  public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        group.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++) group[i]=i;
        
        unordered_map<string,int> mail_to_id;
        // unordered_map<int,owner> id_to_owner;
        for(int owner=0; owner<n; owner++){
            // id_to_owner[owner] = accounts[owner][0];
            for(int email=1; email<accounts[owner].size();email++){
                if(mail_to_id.find(accounts[owner][email]) != mail_to_id.end()){
                    unionGroups(owner, mail_to_id[accounts[owner][email]]);
                }
                else{
                    mail_to_id[accounts[owner][email]] = owner;
                }
            }
        }

        unordered_map<int, set<string>> id_to_mails;
        for(auto mail : mail_to_id){
            id_to_mails[findGroup(mail.second)].insert(mail.first);
        }

        vector<vector<string>> ans;
        for(auto ids : id_to_mails){
            vector<string> temp;
            temp.push_back(accounts[ids.first][0]);
            for(auto mail : ids.second){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;

  }
};