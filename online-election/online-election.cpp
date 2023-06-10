class TopVotedCandidate {
    vector<pair<int, int>> log; // time -> leader
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int,int> cnt_votes; // person -> votes
        int max_votes = -1;
        int leader = -1;
        for(int i=0; i<times.size(); ++i){
            ++cnt_votes[persons[i]];
            if(cnt_votes[persons[i]] >= max_votes){
                max_votes = cnt_votes[persons[i]];
                if(persons[i] != leader){
                    leader = persons[i];
                    log.push_back({times[i], leader});
                }
            }
        }        
        // for(auto& p : log){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
    }
    
    int q(int t) {
        int l = 0;
        int r = log.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(log[mid].first <= t){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return log[ans].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */