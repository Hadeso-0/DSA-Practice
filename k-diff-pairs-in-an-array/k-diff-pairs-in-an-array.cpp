class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> hash;
        unordered_set<string> ans;
        for(int i=0 ;i<nums.size(); ++i){
            if(hash.find(nums[i]+k) != hash.end()){
                // Matlab, isse use krke bana skta
                cout<<nums[i]<<","<<i<<endl;
                ans.insert(to_string(nums[i]+k)+"#"+to_string(nums[i]));
                if(k != 0) 
                    ans.insert(to_string(nums[i])+"#"+to_string(nums[i]+k));
            }
            if(hash.find(nums[i]-k) != hash.end()){
                // Matlab, isse use krke bana skta
                cout<<nums[i]<<","<<i<<endl;
                ans.insert(to_string(nums[i]-k)+"#"+to_string(nums[i]));
                if(k != 0)
                    ans.insert(to_string(nums[i])+"#"+to_string(nums[i]-k));
            }
            hash.insert(nums[i]);
        }
        return k!=0 ? (ans.size()/2) : ans.size();

    }
};