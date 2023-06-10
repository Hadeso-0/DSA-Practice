class Solution {
    int getSum(vector<int>& arr,vector<int>& pre, int val){
        int lastIdx = upper_bound(arr.begin(), arr.end(), val)-arr.begin();
        int numsGreater = arr.size()-lastIdx;
        return (pre[lastIdx] + (numsGreater*val));
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> pre(arr.size()+1,0); pre[0] = 0;
        for(int i=1; i<=arr.size(); ++i){
            pre[i] = pre[i-1] + arr[i-1];
        }
        int l = 0;
        int r = target;
        int ans = target;
        int diff = INT_MAX;
        while(l <= r){
            int mid = l + (r-l)/2;
            auto ubound = upper_bound(arr.begin(), arr.end(), mid);
            if(ubound == arr.end()){
                int sum = pre[pre.size()-1];
                if(abs(target - sum) < diff){
                    diff = abs(target-sum);
                    ans = mid;
                }
                if(abs(target-sum) == diff){
                    ans = min(ans, mid);
                }
                r = mid-1;
            }
            else{
                int sum = getSum(arr, pre, mid);
                cout<<mid<<" "<<sum<<endl;
                if(diff > abs(sum-target)){
                    diff = abs(sum-target);
                    ans = mid;
                }
                if(diff == abs(sum-target)){
                    ans = min(mid,ans);
                }
                if(sum > target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return ans;
    }
};