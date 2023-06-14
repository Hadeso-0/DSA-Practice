class NumArray {
    vector<int> arr;
    vector<int> seg;
    int n;
public:
    void build(int low, int high, int idx){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        build(low, mid, 2*idx+1);
        build(mid+1, high, 2*idx+2);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        seg.resize(4*n);
        build(0, n-1, 0);
    }
    
    void pointUpdate(int low, int high, int idx, int target, int val){
        if(low == high){
            seg[idx] = val;
            arr[low] = val;
            return;
        }
        int mid = low + (high-low)/2;

        if(target <= mid && target >= low)
            pointUpdate(low, mid, 2*idx+1, target, val);
        else 
            pointUpdate(mid+1, high, 2*idx+2, target, val);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    void update(int index, int val) {
        pointUpdate(0, n-1, 0, index, val);   
    }
    
    int query(int low, int high, int idx, int l, int r){
        if(r < low || l > high ) return 0;
        if(l<= low && high <= r){
            return seg[idx];
        }
        int mid = low + (high - low)/2;
        int lft = query(low, mid, 2*idx+1, l, r);
        int rgt = query(mid+1, high, 2*idx+2, l, r);
        return lft + rgt;
    }


    int sumRange(int left, int right) {
        return query(0,n-1,0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */