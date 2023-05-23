class Solution {
    bool isOverlap(vector<int>& real_, vector<int>& new_){
        if( min(real_[1],new_[1]) >= max(real_[0],new_[0])) return true;
        return false;
    }
    void mergeIntervals(vector<int>& real_, vector<int>& new_){
        real_[0] = min(real_[0], new_[0]);
        real_[1] = max(real_[1], new_[1]);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // bool flg = true;
        // for(int i=0; i<intervals.size(); ++i){
        //     if(intervals[i][0] > newInterval[0]){
        //         intervals.insert(intervals.begin()+i, newInterval);
        //         flg = false;
        //         break;
        //     }
        // }
        // if(flg){
        //     intervals.push_back(newInterval);
        // }

        int idx = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        
        if (idx != intervals.size()) {
            intervals.insert(intervals.begin() + idx, newInterval);
        } else {
            intervals.push_back(newInterval);
        }

        // return intervals;


        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); ++i){
            vector<int> temp = intervals[i];
            cout<<i<<" => ";
            ++i;
            while(i<intervals.size() && isOverlap(temp, intervals[i])){
                cout<<i<<" ";
                mergeIntervals(temp, intervals[i]);
                ++i;
            }
            --i;
            ans.push_back(temp);
            cout<<endl;
        }
        return ans;
    }
};