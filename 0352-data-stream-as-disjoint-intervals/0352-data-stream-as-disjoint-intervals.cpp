class SummaryRanges {
public:
    vector<int> prev, next;
    set<int> roots;
    SummaryRanges() {
        prev.resize(10001, -1);
        next.resize(10001, -1);
        roots.clear();
    }
    
    int findPrev(int cur)
    {
        if(prev[cur] == cur)
            return cur;
        return prev[cur] = findPrev(prev[cur]);
    }
    
    int findNext(int cur)
    {
        if(next[cur] == cur)
            return cur;
        return next[cur] = findNext(next[cur]);
        
    }
    
    void addNum(int value) {
        prev[value] = value;
        next[value] = value;
        if(value > 0 && prev[value - 1] != -1)
            prev[value] = prev[value - 1];
        if(value + 1 <= 10000 && next[value + 1] != -1)
            next[value] = next[value + 1];
        if(value > 0 && prev[value - 1] != -1)
            next[value - 1] = next[value];
        if(value + 1 <= 10000 && next[value + 1] != -1){
            prev[value + 1] = prev[value];
            roots.erase(value + 1);
        }
        roots.insert(findPrev(value));
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(int root : roots)
            ans.push_back({root, findNext(root)});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */