class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mp;
        string pref,suff;
        for(auto word : wordList){
            pref = "";
            suff = word.substr(1);
            for(int i=0; i<word.size(); i++){
                mp[pref + "#" + suff].push_back(word);
                pref.push_back(word[i]);
                if(suff.size() > 0) suff = suff.substr(1);
            }
        }

//         for(auto p : mp){
//             cout<<p.first<<"->";
//             for(auto x : p.second){
//                 cout<<x<<" ,";
//             }
//             cout<<endl;
//         }
// cout<<endl;
        queue<pair<string,int>> q;
        q.push({beginWord, 0});
        unordered_map<string,bool> vis;
        vis[beginWord] = true;

        while(!q.empty()){
            string cur = q.front().first;
            int dis = q.front().second;
            q.pop();
            cout<<cur<<" -> ";
            
            pref = "";
            suff = cur.substr(1);
            for(int i=0; i<cur.size(); i++){
                for(auto nex : mp[pref + "#" + suff]){
                    if(!vis[nex]){
                        // cout<<nex<<", " ;
                        if(nex == endWord) return dis+2;
                        q.push({nex, dis+1});
                        vis[nex] = true;
                    }
                }
                pref.push_back(cur[i]);
                if(suff.size() > 0) suff = suff.substr(1);
            }
            // cout<<endl;

        }
        return 0;
    }
};