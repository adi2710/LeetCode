class SnapshotArray {
public:
    vector<vector<pair<int, int>>> ar;
    int cur_snap = 0;
    SnapshotArray(int length) {
        ar.resize(length, vector<pair<int, int>> (1, {0, 0}));
    }
    
    void set(int index, int val) {
        if(ar[index].back().second < cur_snap)
            ar[index].push_back({val, cur_snap});
        else
            ar[index].back().first = val;
    }
    
    int snap() {
        cur_snap++;
        return cur_snap - 1;
    }
    
    int get(int index, int snap_id) {
        int l = 0, r = ar[index].size();
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if(ar[index][mid].second <= snap_id)
                l = mid;
            else
                r = mid;
        }
        return ar[index][l].first;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */