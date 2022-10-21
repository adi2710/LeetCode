class TweetCounts {
public:
    unordered_map<string, vector<int>> tweets;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = 60;
        if(freq == "hour")
            interval *= 60;
        else if(freq == "day")
            interval *= 60 * 24;
        int bucketSize = (endTime - startTime) / interval;
        vector<int> ans(bucketSize + 1);
        for(int &time : tweets[tweetName])
        {
            if(startTime <= time && time <= endTime)
                ans[(time - startTime) / interval]++;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */