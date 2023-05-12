class Solution {
public:
    
    long long solve(int i, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if(i >= questions.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        long long take = questions[i][0] + solve(i + questions[i][1] + 1, questions, dp);
        long long skip =  solve(i + 1, questions, dp);
        return dp[i] = max(take, skip);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return solve(0, questions, dp);
    }
};