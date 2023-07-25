class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        // O(log(n))
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
            if(mid!=arr.size()-1 && arr[mid]<arr[mid+1]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        
        return e;

        // // O(n)
        // pair<int,int> ans={-1,-1};
        // for(int i=0; i<arr.size(); i++){
        //     if(arr[i] > ans.first){
        //         ans = {arr[i],i};
        //     }
        // }
        // return ans.second;
    }
};