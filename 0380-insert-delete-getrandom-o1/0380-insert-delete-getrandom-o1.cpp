class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> pos;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(pos.find(val) == pos.end())
        {
            pos[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(pos.find(val) != pos.end())
        {
            nums[pos[val]] = nums.back();
            pos[nums.back()] = pos[val];
            nums.pop_back();
            pos.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */