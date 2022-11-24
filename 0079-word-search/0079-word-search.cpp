class Solution {
public:
    
    bool bfs(int r, int c, int i, vector<vector<char>> &board, string &word)
    {
        if(i == word.size())
            return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i])
            return false;

        char ch = board[r][c];
        board[r][c] = '.';
        bool fl = bfs(r + 1, c, i + 1, board, word) ||
        bfs(r - 1, c, i + 1, board, word) ||
        bfs(r, c + 1, i + 1, board, word) ||
        bfs(r, c - 1, i + 1, board, word);
        board[r][c] = ch;
        return fl;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        bool fl = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(bfs(i, j, 0, board, word))
                {
                    fl = 1;
                    break;
                }
            }
            if(fl)
                break;
        }
        return fl;
    }
};