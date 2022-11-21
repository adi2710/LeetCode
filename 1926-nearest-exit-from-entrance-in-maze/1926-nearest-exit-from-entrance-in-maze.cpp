class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        int n = maze.size(), m = maze[0].size(), ans = 0;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c] = q.front();
                q.pop();
                if((r != entrance[0] || c != entrance[1]) && (r == 0 || r == n - 1 || c == 0 || c == m - 1))
                    return ans;
                for(int j = 0; j < dx.size(); j++)
                {
                    int row = r + dx[j], col = c + dy[j];
                    if(row < 0 || row >= n || col < 0 || col >= m || maze[row][col] == '+')
                        continue;
                    maze[row][col] = '+';
                    q.push({row, col});
                }
            }
            ans++;
        }
        return -1;
    }
};