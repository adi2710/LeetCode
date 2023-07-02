class Solution {
public:
    
    int solve(int i, vector<int> &people, vector<vector<int>> &requests)
    {
        if(i == requests.size())
        {
            int mx = *max_element(people.begin(), people.end());
            if(mx == 0)
                return 0;
            return INT_MIN;
        }
        people[requests[i][0]]--;
        people[requests[i][1]]++;
        int n1 = 1 + solve(i + 1, people, requests);
        people[requests[i][0]]++;
        people[requests[i][1]]--;
        int n2 = solve(i + 1, people, requests);
        return max(n1, n2);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> people(n);
        return solve(0, people, requests);
    }
};
