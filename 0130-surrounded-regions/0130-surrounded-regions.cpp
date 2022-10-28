class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    void dfs(int r, int c, vector<vector<char>> &board)
    {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O')
            return;
        board[r][c] = '#';
        for(int i = 0; i < 4; i++)
            dfs(r + dx[i], c + dy[i], board);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O')
                dfs(i, 0, board);
            if(board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O')
                dfs(0, j, board);
            if(board[n - 1][j] == 'O')
                dfs(n - 1, j, board);
        }
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(board[r][c] == 'O')
                    board[r][c] = 'X';
                else if(board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};