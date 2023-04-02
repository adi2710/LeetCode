//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        queue<pair<int, int>> q;
        vector<int> points;
        points.push_back(arr[start_x][start_y]);
        arr[start_x][start_y] = -1;
        q.push({start_x, start_y});
        vector<int> dx = {-2, -2, 2, 2, -1, -1, 1, 1}, dy = {-1, 1, -1, 1, -2, 2, -2, 2};;
        int n = arr.size(), m = arr[0].size();
        while(!q.empty())
        {
            int point = 0;
            for(int i = q.size(); i >= 1; i--)
            {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int i = 0; i < dx.size(); i++)
                {
                    int new_r = r + dx[i], new_c = c + dy[i];
                    if(0 <= new_r && new_r < n && 0 <= new_c && new_c < m && arr[new_r][new_c] != -1){
                        point += arr[new_r][new_c];
                        arr[new_r][new_c] = -1;
                        q.push({new_r, new_c});
                    }
                }
            }
            points.push_back(point);
        }
        for(int i = points.size() - 1; i >= 0; i--)
        {
            if(i + points[i] < points.size())
                points[i] += points[i + points[i]];
        }
        return max_element(points.begin(), points.end()) - points.begin();
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends