class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int N = 26;
        vector<vector<int>> costMat(N, vector<int> (26, INT_MAX));
        for(int i = 0; i < N; i++) {
            costMat[i][i] = 0;
        }
        for(int i = 0; i < original.size(); i++) {
            costMat[original[i] - 'a'][changed[i] - 'a'] = 
                min(costMat[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(costMat[i][k] != INT_MAX && costMat[k][j] != INT_MAX 
                       && costMat[i][k] + costMat[k][j] < costMat[i][j]) {
                        costMat[i][j] = costMat[i][k] + costMat[k][j];
                    }
                }
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(costMat[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
                return -1;
            
            ans += costMat[source[i] - 'a'][target[i] - 'a']; 
        }
        
        return ans;
    }
};