#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_multiset = tree<
    T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Router {
    unordered_set<long long> packetsSet;
    queue<vector<int>> packetsQueue;
    unordered_map<int, ordered_multiset<int>> packetsMap;
    int memoryLimit;

    long long getPacketHash(int source, int destination, int timestamp) {
        long long val = 2e5;
        return (source * val + destination) * val + timestamp;
    }
public:
    Router(int memoryLimit) {
        this -> memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long packetHash = getPacketHash(source, destination, timestamp);
        if(packetsSet.find(packetHash) != packetsSet.end()) {
            return false;
        }
        if(packetsQueue.size() == memoryLimit) {
            forwardPacket();
        }
        packetsQueue.push({source, destination, timestamp});
        packetsSet.insert(packetHash);
        packetsMap[destination].insert(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetsQueue.empty()) {
            return {};
        }
        vector<int> packet = packetsQueue.front();
        packetsQueue.pop();
        packetsSet.erase(getPacketHash(packet[0], packet[1], packet[2]));
        auto &os = packetsMap[packet[1]];
        int idx = os.order_of_key(packet[2]);
        if (idx < (int)os.size() && *os.find_by_order(idx) == packet[2]) {
            os.erase(os.find_by_order(idx));
        }
        if(packetsMap[packet[1]].empty()) {
            packetsMap.erase(packet[1]);
        }
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &val = packetsMap[destination];
        return val.order_of_key(endTime + 1) - val.order_of_key(startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */