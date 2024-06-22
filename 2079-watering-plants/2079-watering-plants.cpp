class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0, cap = capacity, i = 0;
        while (i < plants.size()) {
            if (plants[i] <= cap) {
                ans++;
                cap -= plants[i];
                plants[i] = 0;
                i++;
            } else {
                ans += 2 * i + 1;
                cap = capacity;
                cap -= plants[i];
                i++;
            }
        }
        return ans;
    }
};