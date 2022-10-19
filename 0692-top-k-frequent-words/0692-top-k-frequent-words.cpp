class Solution {
public:
    
    struct compare{
        bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(string &st : words)
            freq[st]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        for(auto &[word, cnt] : freq)
        {
            pq.push({cnt, word});
            if(pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};