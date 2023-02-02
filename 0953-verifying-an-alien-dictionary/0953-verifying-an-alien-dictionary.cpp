class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(26);
        for(int i = 0; i < order.size(); i++)
            pos[order[i] - 'a'] = i;
        return is_sorted(words.begin(), words.end(), [&](const string &a, const string &b){
            int i;
            for(i = 0; i < min(a.size(), b.size()) && a[i] == b[i]; i++);
            if(i == a.size() && i == b.size())
                return false;
            else if(i == a.size())
                return true;
            else if(i == b.size())
                return false;
            else if(pos[a[i] - 'a'] < pos[b[i] - 'a'])
                return true;
            return false;
        });
    }
};