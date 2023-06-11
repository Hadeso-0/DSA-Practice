class SnapshotArray {
    vector<vector<pair<int,int>>> nums;
    int snaps_taken;
public:
    SnapshotArray(int length) {
        snaps_taken = 0;
        nums.resize(length);
        for(int i=0; i<length; ++i){
            nums[i].push_back({-1,0});
        }
    }
    
    void set(int index, int val) {
        nums[index].push_back({snaps_taken, val});
    }
    
    int snap() {
        ++snaps_taken;
        return snaps_taken-1;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(nums[index].begin(), nums[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */