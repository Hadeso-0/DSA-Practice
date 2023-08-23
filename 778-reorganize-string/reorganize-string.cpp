class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(int i=0; i<s.size(); ++i) 
            ++mp[s[i]];

        for(auto& i : mp){
            pq.push({i.second, i.first});
        }
        string ans = "";
        char prev = '\0';

        while(pq.size() >= 2){
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();

            if(prev != p1.second){
                ans.push_back(p1.second);
                ans.push_back(p2.second);
                prev = p2.second;
            }
            else{
                ans.push_back(p2.second);
                ans.push_back(p2.second);
                prev = p1.second;
            }
            
            --p1.first; --p2.first;
            if(p1.first > 0){
                pq.push(p1);
            }
            if(p2.first > 0){
                pq.push(p2);
            }
        }

        if(!pq.empty() && (prev != pq.top().second)){
            ans.push_back(pq.top().second);
        }
        
        if(ans.size() == s.size())  
            return ans;
        
        return "";
    }
};