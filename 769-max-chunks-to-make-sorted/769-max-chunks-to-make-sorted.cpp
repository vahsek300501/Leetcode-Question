class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int chunkCount = 0;
        int cntMax = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.at(i) > cntMax)
                cntMax = arr.at(i);
            if (i == cntMax)
                chunkCount++;
        }
        return chunkCount;
    }
};