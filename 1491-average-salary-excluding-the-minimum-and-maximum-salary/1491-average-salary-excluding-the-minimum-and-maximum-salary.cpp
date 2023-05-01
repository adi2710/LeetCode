class Solution {
public:
    double average(vector<int>& salary) {
        int sum = accumulate(salary.begin(), salary.end(), 0);
        int mn = *min_element(salary.begin(), salary.end());
        int mx = *max_element(salary.begin(), salary.end());
        return 1.0 * (sum - mx - mn) / (salary.size() - 2);
    }
};