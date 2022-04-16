class BrowserHistory {
    stack<string> forwardStack;
    stack<string> backStack;
public:
    BrowserHistory(string homepage) {
        forwardStack.push(homepage);
    }

    void visit(string url) {
        forwardStack.push(url);
        if (!backStack.empty()) {
            while (backStack.size() > 0)
                backStack.pop();
        }
    }

    string back(int steps) {
        int tmpSteps = steps;
        while (true){
            if(tmpSteps == 0 || forwardStack.size() == 1)
                break;
            string tmp = forwardStack.top();
            backStack.push(tmp);
            forwardStack.pop();
            tmpSteps--;
        }
        return forwardStack.top();
    }

    string forward(int steps) {
        if (backStack.empty())
            return forwardStack.top();
        int tmpSteps = steps;
        while (true){
            if(tmpSteps == 0 || backStack.empty())
                break;
            forwardStack.push(backStack.top());
            backStack.pop();
            tmpSteps--;
        }
        return forwardStack.top();
    }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */