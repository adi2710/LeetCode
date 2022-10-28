class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    bool dfs(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &vis)
    {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return false;
        if(board[r][c] == 'X' || vis[r][c])
            return true;
        vis[r][c] = true;
        bool fl = true;
        for(int i = 0; i < 4; i++)
        {
            int row = r + dx[i], col = c + dy[i];
            fl = dfs(row, col, board, vis) && fl;
        }
        return fl;
    }
    
    void dfs2(int r, int c, vector<vector<char>> &board)
    {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 'X')
            return;
        board[r][c] = 'X';
        for(int i = 0; i < 4; i++)
        {
            int row = r + dx[i], col = c + dy[i];
            dfs2(row, col, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m));
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'O' && !vis[i][j]){
                    if(dfs(i, j, board, vis))
                        dfs2(i, j, board);
                }
            }
        }
    }
};