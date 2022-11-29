class Solution {
public:
    
    vector<int> d = {-1, 0, 1};
    
    void clickAction(int r, int c, vector<vector<char>> &board)
    {
        if(board[r][c] == 'M')
        {
            board[r][c] = 'X';
            return;
        }
        
        else if(board[r][c] == 'E')
        {
            int cntMines = 0;
            for(int x : d)
            {
                for(int y : d)
                {
                    if(x == 0 && y == 0)
                        continue;
                    int row = r + x, col = c + y;
                    if(row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && (board[row][col] == 'M' || board[row][col] == 'X'))
                        cntMines++;
                }
            }
            if(cntMines == 0)
            {
                board[r][c] = 'B';
                for(int x : d)
                {
                    for(int y : d)
                    {
                        if(x == 0 && y == 0)
                            continue;
                        int row = r + x, col = c + y;
                        if(row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && (board[row][col] == 'E' || board[row][col] == 'M'))
                            clickAction(row, col, board);
                    }
                }
            }
            else
                board[r][c] = '0' + cntMines;
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        clickAction(click[0], click[1], board);
        return board;
    }
};