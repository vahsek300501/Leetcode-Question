class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forbidIndex;
        for(auto f:forbidden){
            forbidIndex.insert(f);
        }
        vector<pair<bool,bool>> visited(6000, {false, false}); // visited when can go back, when can't
        visited[0].first = true;
        queue<pair<int, bool>> q; // {current index, if prev step is jump backward}
        q.push({0, false});
        int stepCount = 0;
        while(q.size()){
            int size = q.size();
            while(size--){
                int curIndex = q.front().first;
                bool prevBackWard = q.front().second;
                q.pop();
                if(curIndex == x){
                    return stepCount;
                }else{
                    int nextIndex = curIndex+a;
                    if(nextIndex < 6000 && forbidIndex.count(nextIndex)==0 && !visited[nextIndex].first){
                        q.push({nextIndex, false});
                        visited[nextIndex].first = true;
                    }
                    if(!prevBackWard){ // we can jump backward now!
                        nextIndex = curIndex-b;
                        if(nextIndex > 0 && forbidIndex.count(nextIndex)==0 && !visited[nextIndex].second){
                            q.push({nextIndex, true});
                            visited[nextIndex].second = true;
                        }
                    }
                }
            }
            stepCount++;
        }
        return -1;
    }
};