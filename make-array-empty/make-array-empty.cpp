class SegTree {
    vector<int> tree;
    int n;
    int queryTree(int idx, int low, int high, int l ,int r){
        if( l > r) return 0;
        if(r < low || l > high) return 0;
        if(l <= low && r >= high) return tree[idx];

        int mid = low + (high - low)/2;
        int left = queryTree(2*idx+1, low, mid, l, r);
        int right = queryTree(2*idx+2, mid+1, high, l, r);

        return left + right;
    }
    void buildTree(int idx, int low, int high){
        if(low == high){
            tree[idx] = 1;
            return;
        }

        int mid = low + (high - low)/2;
        buildTree(2*idx+1, low, mid);
        buildTree(2*idx+2, mid+1, high);

        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }
    void updateTree(int idx, int low, int high, int tar){
        if((tar < low) || (tar > high)) return;
        if(low == tar && high == low){
            tree[idx] = 0;
            return;
        }

        int mid = low + (high - low)/2;
        
        if((tar <= mid) && (tar >= low))
            updateTree(2*idx+1, low, mid,tar);
        else
            updateTree(2*idx+2, mid+1, high, tar);

        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }
    public:
    SegTree(int n){
        tree.resize(4*n);
        this->n = n;
        buildTree(0, 0, n-1);
    }
    void update(int tar){
        updateTree(0, 0, n-1, tar);
    }
    int query(int l, int r){
        return queryTree(0, 0, n-1, l, r);
    }
};
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<vector<int>> temp;
        for(int i=0; i<n; ++i){
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());

        SegTree* sg = new SegTree(n);
        
        int cur_front = -1;
        for(int i=0; i<n-1; ++i){
            int old_pos = temp[i][1];

            if(cur_front < old_pos){
                // I need to remove elements from [cur_front+1 ... old_pos-1]
                int num_els = sg->query(cur_front+1, old_pos-1);
                ans = ans + num_els + 1LL;
            }
            else{
                // I need to remove elements from [cur_front+1 ... end] + [start, old_pos-1]
                int num_els = sg->query(cur_front+1, n-1);
                num_els += sg->query(0, old_pos-1);
                ans = ans + num_els + 1LL;
            }
            sg->update(old_pos);
            cur_front = old_pos;
        }
        return ans+1;
    }
};