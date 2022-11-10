//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    void floodFill(int r, int c, int color, vector<vector<int>> &image)
    {
        int prev = image[r][c];
        image[r][c] = color;
        for(int i = 0; i < 4; i++)
        {
            int row = r + dx[i], col = c + dy[i];
            if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != prev)
                continue;
            floodFill(row, col, color, image);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(image[sr][sc] == newColor)
            return image;
        floodFill(sr, sc, newColor, image);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends