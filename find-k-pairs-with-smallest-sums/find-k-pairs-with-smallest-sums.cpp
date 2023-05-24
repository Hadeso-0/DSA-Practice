class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n1 = nums1.size();
        int n2 = nums2.size();
        map<vector<int>, bool> vis;
        vector<vector<int>> ans;

        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        pq.push({nums1[0]+nums2[0], 0, 0});
        vis[{0,0}] = true;

        
        while(k && !pq.empty()){
            int i = (pq.top())[1]; 
            int j = (pq.top())[2];
            ans.push_back({nums1[i],nums2[j]});
            pq.pop();

            if(i+1 < n1 && vis[{i+1, j}]==false){
                pq.push({nums1[i+1]+nums2[j] ,i+1, j});
                vis[{i+1, j}] = true;
            } 
            if(j+1 < n2 && vis[{i, j+1}]==false){
                pq.push({nums1[i]+nums2[j+1] ,i, j+1});
                vis[{i, j+1}] = true;
            } 
            --k;
        }
        return ans;
    }
};