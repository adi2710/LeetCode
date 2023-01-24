class Solution {
public:
    
    int convert(int cell, vector<vector<int>> &board)
    {
        int n = board.size();
        int row = (cell - 1) / n;
        int col = (cell - 1) % n;
        if(row & 1)
            col = n - col - 1;
        row = n - row - 1;
        return (board[row][col] == -1 ? cell : board[row][col]);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        vector<bool> vis(n * n + 1);
        q.push(1);
        vis[1] = true;
        int ans = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                int cell = q.front();
                q.pop();
                if(cell == n * n)
                    return ans;
                for(int new_cell = cell + 1; new_cell - cell <= 6 && new_cell <= n * n; new_cell++)
                {
                    int abs_new_cell = convert(new_cell, board);
                    if(!vis[abs_new_cell])
                    {
                        q.push(abs_new_cell);
                        vis[abs_new_cell] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};