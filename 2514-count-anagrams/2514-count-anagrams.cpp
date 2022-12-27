class Solution {
public:
    
    static const int N = 1e5 + 5, MOD = 1e9 + 7;
    int fact[N], inv_fact[N];
    
    void precompute()
    {
        fact[0] = inv_fact[0] = 1;
        for(int i = 1; i < N; i++){
            fact[i] = (1ll * fact[i - 1] * i) % MOD;
            inv_fact[i] = power(fact[i], MOD - 2);
        }
    }
    
    int power(int a, int b)
    {
        int res = 1;
        while(b)
        {
            if(b & 1)
                res = (1ll * res * a) % MOD;
            a = (1ll * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    
    int countAnagrams(string s) {
        precompute();
        stringstream ss(s);
        string word;
        int ans = 1;
        while(ss >> word)
        {
            vector<int> freq(26);
            ans = (1ll * ans * fact[word.size()]) % MOD;
            for(char ch : word)
                freq[ch - 'a']++;
            for(int i = 0; i < 26; i++)
                ans = (1ll * ans * inv_fact[freq[i]]) % MOD;
        }
        return ans;
    }
};