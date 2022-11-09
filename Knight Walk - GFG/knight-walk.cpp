//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    // Code here
	    vector<int> dx = {-2, -2, 2, 2, -1, 1, -1, 1}, dy = {-1, 1, -1, 1, -2, -2, 2, 2};
	    vector<vector<bool>> vis(n, vector<bool> (n));
	    int ans = 0;
	    queue<pair<int, int>> q;
	    q.push({KnightPos[0] - 1, KnightPos[1] - 1});
	    vis[KnightPos[0] - 1][KnightPos[1] - 1] = true;
	    while(!q.empty())
	    {
	        for(int i = q.size(); i >= 1; i--)
	        {
	            int r = q.front().first, c = q.front().second;
	            q.pop();
	            if(r == TargetPos[0] - 1 && c == TargetPos[1] - 1)
	                return ans;
	            for(int j = 0; j < 8; j++)
	            {
	                int row = r + dx[j], col = c + dy[j];
	                if(row < 0 || row >= n || col < 0 || col >= n || vis[row][col])
	                    continue;
	                vis[row][col] = true;
	                q.push({row, col});
	            }
	        }
	        ans++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends