class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        const int MOD = 256;
        vector<int> dx = {-1, 0, 1};
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                int sum = 0, count = 0;
                for(int dr : dx) {
                    for(int dc : dx) {
                        int row = r + dr, col = c + dc;
                        if(row < 0 || row >= n || col < 0 || col >= m)
                            continue;
                        sum += img[row][col] % MOD;
                        count++;
                    }
                }
                img[r][c] = sum / count * MOD + img[r][c];
            }
        }
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                img[r][c] /= MOD;
            }
        }
        return img;
    }
};