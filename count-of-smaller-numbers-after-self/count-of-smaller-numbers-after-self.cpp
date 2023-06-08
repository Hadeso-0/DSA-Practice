class Solution {
    // vector<int> ans;
    void merge(vector<pair<int,int>>& nums, int s, int mid, int e, vector<int>& ans){
        vector<pair<int,int>> temp(e-s+1);
        int i = s;
        int j = mid+1;
        int processed = 0;
        int pos = 0;
        while(i<=mid && j<=e){
            if(nums[j].first < nums[i].first){
                temp[pos++] = nums[j];
                ++processed;
                ++j;
            }
            else{
                temp[pos++] = nums[i];
                ans[nums[i].second] += processed;
                ++i;
            }
        }
        while(i<=mid){
            temp[pos++] = nums[i];
            ans[nums[i].second] += processed;
            ++i;
        }
        while(j<=e){
            temp[pos++] = nums[j];
            ++j;
        }
        for(int i=s; i<=e; ++i){
            nums[i] = temp[i-s];
        }
    }
    void mergeSort(vector<pair<int,int>>& nums, int s, int e, vector<int>& ans){
        if(s == e) return;

        int mid = s + (e-s)/2;
        mergeSort(nums, s, mid, ans);
        mergeSort(nums, mid+1, e, ans);
        merge(nums, s, mid, e, ans);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; ++i){
            arr.push_back({nums[i], i});
        }
        vector<int> ans(n,0);
        mergeSort(arr, 0, n-1, ans);
        return ans;
    }
};