class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        int n = board.size();
        for(int i = 0; i < n; i++)
        {
            vector<bool> vis(10);
            for(int j = 0; j < n; j++)
            {
                if(isdigit(board[i][j]))
                {
                    if(vis[board[i][j] - '0'])
                        return false;
                    else
                        vis[board[i][j] - '0'] = true;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            vector<bool> vis(10);
            for(int j = 0; j < n; j++)
            {
                if(isdigit(board[j][i]))
                {
                    if(vis[board[j][i] - '0'])
                        return false;
                    else
                        vis[board[j][i] - '0'] = true;
                }
            }
        }
        for(int i = 0; i < n; i += 3)
        {
            for(int j = 0; j < n; j += 3)
            {
                vector<bool> vis(10);
                for(int k = i; k - i < 3; k++)
                {
                    for(int l = j; l - j < 3; l++)
                    {
                        if(isdigit(board[k][l]))
                        {
                            if(vis[board[k][l] - '0'])
                                return false;
                            else
                                vis[board[k][l] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};