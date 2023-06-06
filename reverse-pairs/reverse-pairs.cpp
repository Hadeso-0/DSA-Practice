class Solution {
    int mergeArr(vector<int>& nums, int s, int mid, int e){
        int i = s;
        int j = mid+1;
        int ans = 0;
        int y = mid+1;
        for(int x=s; x<=mid; ++x){
            while(y<=e && nums[x] > 2LL*nums[y]) ++y;
            ans += (y-mid-1);
        }
        

        // cout<<"merging "<<s<<"-"<<mid<<"-"<<e<<" ";
        vector<int> temp;
        while(i<=mid && j<=e){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]); ++i;
            }
            else{
                temp.push_back(nums[j]);
                ++j;
            }
        }
        while(j<=e){
            temp.push_back(nums[j]);
            ++j;
        }
        while(i<=mid){
            temp.push_back(nums[i]); ++i;
        }
        for(int k=s; k<=e; ++k){ nums[k] = temp[k-s]; }
        cout<<ans<<endl;
        return ans;
    }
    int mergeSort(vector<int>& nums, int s, int e){
        if(s >= e) return 0;
        int mid = s + (e-s)/2;
        return mergeSort(nums, s, mid) + mergeSort(nums, mid+1, e) + mergeArr(nums, s, mid, e); 
    }
public:
    int reversePairs(vector<int>& nums) {

        // O(n log(n))
        int n = nums.size();
        return mergeSort(nums, 0, n-1);

        // // O(n^2)
        // int n = nums.size();
        // int ans = 0;
        // for(int j=1; j<n; ++j){
        //     for(int i=0; i<j; ++i){
        //         if(nums[i] > 2LL*nums[j]) ++ans; 
        //     }
        // }
        // return ans;
    }
};