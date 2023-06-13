class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1;
        for(int i=0; i<nums1.size(); ++i){
            mp1[nums1[i]] = i;
        }   

        vector<int> ans(nums1.size());
        stack<int> ng;
        ng.push(1e8);
        for(int i=nums2.size()-1; i>=0; --i){
            while(nums2[i] > ng.top()){
                ng.pop();
            }
            // cout<<nums2[i]<<" ";
            if(mp1.find(nums2[i]) != mp1.end()){
                if(ng.top() == 1e8) ans[mp1[nums2[i]]] = -1;
                else ans[mp1[nums2[i]]] = ng.top();
            }
            ng.push(nums2[i]);
        }
        return ans;
    }
};