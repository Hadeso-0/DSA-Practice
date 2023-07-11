class Solution {
    void add(multiset<int>& left, multiset<int>& right, int val,int k){
        if(left.size() < (k/2)){
            left.insert(val);
        }
        else{
            if(*prev(left.end()) > val){
                right.insert(*prev(left.end()));
                left.erase(left.find(*prev(left.end())));
                left.insert(val);
            }
            else{
                right.insert(val);
            }
        }
    }
    void remove(multiset<int>& left, multiset<int>& right, int val,int k){
        if(left.find(val) != left.end()){
            left.erase(left.find(val));
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        else{
            right.erase(right.find(val));
        }
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n = nums.size();
        
        if(k == 1){
            for(int i=0; i<n; ++i){
                ans.push_back((double)nums[i]);
            }
            return ans;
        }
        multiset<int> left;
        multiset<int> right;
        
        for(int i=0; i<(k); ++i){
            add(left, right, nums[i], k);   
        }
        if(k%2 == 0){
            ans.push_back((double)((double)(*prev(left.end())) + (double)(*right.begin()))/((double)2.0));
        }
        else{
            ans.push_back((double)(*right.begin()));
        }
        // for(auto& p : left) cout<<p<<" ";
        // cout<<" -> ";
        // for(auto& p : right) cout<<p<<" ";
        // cout<<endl;
        for(int i=k; i<n; ++i){
            remove(left, right, nums[i-k], k);
            add(left, right, nums[i], k);

            // for(auto& p : left) cout<<p<<" ";
            // cout<<" -> ";
            // for(auto& p : right) cout<<p<<" ";
            // cout<<endl;
            
            if(k%2 == 0){
                ans.push_back((double)((double)(*prev(left.end())) + (double)(*right.begin()))/((double)2.0));
            }
            else{
                ans.push_back((double)(*right.begin()));
            }
        }
        return ans;
    }
};