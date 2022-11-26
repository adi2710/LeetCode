class Trie{
public:
    vector<Trie*> child;
    Trie()
    {
        child.resize(2, nullptr);
    }
    
    void insert(int num)
    {
        Trie *cur = this;
        for(int i = 31; i >= 0; i--)
        {
            int isSet = (num & (1 << i)) > 0;
            if(cur -> child[isSet] == nullptr)
                cur -> child[isSet] = new Trie();
            cur = cur -> child[isSet];
        }
    }
    
    int maxXor(int num)
    {
        Trie *cur = this;
        int sum = 0;
        for(int i = 31; i >= 0; i--)
        {
            int isSet = (num & (1 << i)) == 0;
            if(cur -> child[isSet] != nullptr){
                cur = cur -> child[isSet];
                sum = (sum << 1) | 1;
            }
            else{
                sum = sum << 1;
                cur = cur -> child[1 - isSet];
            }
        }
        return sum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            trie -> insert(nums[i]);
            ans = max(ans, trie -> maxXor(nums[i]));
        }
        return ans;
    }
};