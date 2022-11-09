//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:

    static const int N = 10000;
    bool pr[N];
    
    void sieve()
    {
        for(int i = 2; i * i < N; i++)
        {
            if(!pr[i])
            {
                for(int j = i * i; j < N; j += i)
                    pr[j] = 1;
            }
        }
    }
    
    int solve(int num1,int num2)
    {
        sieve();
        queue<int> q;
        unordered_set<int> vis;
        q.push(num1);
        vis.insert(num1);
        int ans = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                int cur = q.front();
                q.pop();
                if(cur == num2)
                    return ans;
                for(int j = 1; cur / j > 0; j *= 10)
                {
                    int num = cur, dig = (num / j) % 10;
                    num -= dig * j;
                    for(int a = 0; a <= 9; a++)
                    {
                        if(num / 1000 > 0 && !pr[num] && vis.find(num) == vis.end())
                        {
                            vis.insert(num);
                            q.push(num);
                        }
                        num += j;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends