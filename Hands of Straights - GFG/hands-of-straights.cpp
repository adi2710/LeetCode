//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N % groupSize != 0)
            return false;
        map<int, int> mp;
        for(int x : hand)
            mp[x]++;
        while(!mp.empty())
        {
            for(int i = (*mp.begin()).first, st = i; i - st + 1 <= groupSize; i++)
            {
                if(mp.find(i) == mp.end())
                    return false;
                mp[i]--;
                if(mp[i] == 0)
                    mp.erase(i);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends