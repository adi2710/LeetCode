/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    int isAllOne(int r1, int c1, int r2, int c2, vector<vector<int>> &dp)
    {
        int sum = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
        int count = (r2 - r1 + 1) * (c2 - c1 + 1);
        if(sum == count)
            return 1;
        else if(sum == 0)
            return 0;
        return -1;
    }
    
    Node* construct(int r1, int c1, int r2, int c2, vector<vector<int>> &dp)
    {
        if(r1 == r2 && c1 == c2){
            Node *root = new Node();
            root -> isLeaf = 1;
            root -> val = isAllOne(r1, c1, r2, c2, dp);
            return root;
        }
        int mid_r = (r1 + r2) / 2, mid_c = (c1 + c2) / 2;
        int topLeft = isAllOne(r1, c1, mid_r, mid_c, dp);
        int topRight = isAllOne(r1, mid_c + 1, mid_r, c2, dp);
        int bottomLeft = isAllOne(mid_r + 1, c1, r2, mid_c, dp);
        int bottomRight = isAllOne(mid_r + 1, mid_c + 1, r2, c2, dp);
        Node *root = new Node();
        if(topLeft == 1 && topRight == 1 && bottomLeft == 1 && bottomRight == 1)
        {
            root -> isLeaf = 1;
            root -> val = 1;
        }
        else if(topLeft == 0 && topRight == 0 && bottomLeft == 0 && bottomRight == 0)
        {
            root -> isLeaf = 1;
            root -> val = 0;
        }
        else
        {
            root -> isLeaf = 0;
            root -> val = 0;
            root -> topLeft = construct(r1, c1, mid_r, mid_c, dp);
            root -> topRight = construct(r1, mid_c + 1, mid_r, c2, dp);
            root -> bottomLeft = construct(mid_r + 1, c1, r2, mid_c, dp);
            root -> bottomRight = construct(mid_r + 1, mid_c + 1, r2, c2, dp);
        }
        return root;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= m; j++)
            {
                sum += grid[i - 1][j - 1];
                dp[i][j] = dp[i - 1][j] + sum;
            }
        }
        return construct(1, 1, n, m, dp);
    }
};