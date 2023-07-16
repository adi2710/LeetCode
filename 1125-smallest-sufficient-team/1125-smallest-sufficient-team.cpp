class Solution {
public:
    
    long long solve(int i, int skills, int &tot, unordered_map<string, int> &mp, vector<vector<string>> &people, vector<vector<long long>> &dp)
    {
        if(skills == tot)
            return 0;
        if(i == people.size())
            return LLONG_MAX;
        if(dp[i][skills] != -1)
            return dp[i][skills];
        long long skip = solve(i + 1, skills, tot, mp, people, dp);
        int new_skills = skills;
        for(string &skill : people[i])
            new_skills |= (1 << mp[skill]);
        long long take = solve(i + 1, new_skills, tot, mp, people, dp);
        take |= (1ll << i);
        if(__builtin_popcountll(take) < __builtin_popcountll(skip))
            return dp[i][skills] = take;
        return dp[i][skills] = skip;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        for(int i = 0; i < req_skills.size(); i++)
            mp[req_skills[i]] = i;
        int tot = (1 << (int)req_skills.size()) - 1;
        vector<vector<long long>> dp(people.size(), vector<long long> (tot + 1, -1));
        long long mask = solve(0, 0, tot, mp, people, dp);
        vector<int> ans;
        for(int i = 0; i < people.size(); i++)
        {
            if(mask & (1ll << i))
                ans.push_back(i);
        }
        return ans;
    }
};