class Solution {
public:
    
    pair<int, int> convert(int cell, int n)
    {
        int row = n - 1 - (cell - 1) / n;
        int col = (cell - 1) % n;
        if((row & 1 ^ 1) && (n & 1 ^ 1))
            col = n - 1 - col;
        else if((row & 1) && (n & 1))
            col = n - 1 - col;
        return {row, col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), ans = 0;
        vector<bool> vis(n * n + 1);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty())
        {
            ans++;
            for(int i = q.size(); i >= 1; i--)
            {
                int cell = q.front();
                q.pop();
                if(cell == n * n)
                    return ans - 1;
                for(int new_cell = cell + 1; new_cell - cell <= 6 && new_cell <= n * n; new_cell++)
                {
                    auto [row, col] = convert(new_cell, n);
                    if(board[row][col] != -1 && !vis[board[row][col]])
                        q.push(board[row][col]), vis[board[row][col]] = 1;
                    else if(board[row][col] == -1 && !vis[new_cell])
                        q.push(new_cell), vis[new_cell] = 1;
                }
            }
        }
        return -1;
    }
};