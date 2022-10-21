class BrowserHistory {
public:
    list<string> ls;
    list<string> :: iterator curPage;
    
    BrowserHistory(string homepage) {
        ls.push_back(homepage);
        curPage = ls.begin();
    }
    
    void visit(string url) {
        auto it = curPage;
        ls.erase(++it, ls.end());
        ls.push_back(url);
        curPage++;
    }
    
    string back(int steps) {
        while(steps-- && curPage != ls.begin())
            curPage--;
        return *curPage;
    }
    
    string forward(int steps) {
        while(steps-- && curPage != (--ls.end()))
            curPage++;
        return *curPage;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */