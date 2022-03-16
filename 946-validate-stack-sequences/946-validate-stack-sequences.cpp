class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pushSize = pushed.size();
        int popSize = popped.size();
        int j = 0;
        for(int i=0;i<pushSize;i++) {
            while(!s.empty() && s.top() == popped.at(j)) {
                s.pop();
                j++;
            }
            s.push(pushed.at(i));
        }
        while(!s.empty() && s.top() == popped.at(j)) {
            s.pop();
            j++;
        }
        if(j == popSize)
            return true;
        return false;
    }
};