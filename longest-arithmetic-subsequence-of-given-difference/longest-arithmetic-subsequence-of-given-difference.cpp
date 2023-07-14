class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 1;
        int n = arr.size();
        unordered_map<int,int> val_to_length; 
        // Maps a element in arr to length of longest seq. ending at that value

        for(int i=0; i<n; ++i){
            if(val_to_length.find(arr[i]-difference) == val_to_length.end()){
                val_to_length[arr[i]] = 1;
            }
            else{
                val_to_length[arr[i]] = max(val_to_length[arr[i]], 1+val_to_length[arr[i]-difference]);
                ans = max(ans, val_to_length[arr[i]]);
            }
        }
        return ans;
    }
};