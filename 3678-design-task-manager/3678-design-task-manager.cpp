class TaskManager {
    map<int, set<int>> priorities;
    unordered_map<int, pair<int, int>> tasks;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks[taskId] = {userId, priority};
        priorities[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, prevPriority] = tasks[taskId];
        if(prevPriority == newPriority) {
            return;
        }
        priorities[prevPriority].erase(taskId);
        if(priorities[prevPriority].empty()) {
            priorities.erase(prevPriority);
        }
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = tasks[taskId];
        priorities[priority].erase(taskId);
        if(priorities[priority].empty()) {
            priorities.erase(priority);
        }
        tasks.erase(taskId);
    }
    
    int execTop() {
        if(priorities.empty()) {
            return -1;
        }
        auto mostPriority = --priorities.end();
        int taskId = *(--(*mostPriority).second.end());
        int userId = tasks[taskId].first;
        rmv(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */