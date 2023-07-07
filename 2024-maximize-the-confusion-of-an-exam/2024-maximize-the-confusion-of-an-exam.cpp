class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int first = 0;
        int second = 0;
        int swappableElements = k;
        int maxi = INT_MIN;
        int count = 0;
        while (second < answerKey.size()) {
            if (answerKey[second] == 'T') {
                count++;
                maxi = max(maxi, count);
                second++;
                continue;
            } else {
                if (swappableElements > 0) {
                    count++;
                    maxi = max(maxi, count);
                    second++;
                    swappableElements--;
                    continue;
                } else {
                    while (first < second) {
                        if (answerKey[first] == 'T') {
                            first++;
                            count--;
                        } else {
                            first++;
                            swappableElements++;
                            count--;
                            break;
                        }
                    }
                    maxi = max(maxi, count);
                }
            }
            maxi = max(maxi, count);
        }

        first = 0;
        second = 0;
        swappableElements = k;
        count = 0;

        while (second < answerKey.size()) {
            if (answerKey[second] == 'F') {
                count++;
                maxi = max(maxi, count);
                second++;
                continue;
            } else {
                if (swappableElements > 0) {
                    count++;
                    maxi = max(maxi, count);
                    second++;
                    swappableElements--;
                    continue;
                } else {
                    while (first < second) {
                        if (answerKey[first] == 'F') {
                            first++;
                            count--;
                        } else {
                            first++;
                            swappableElements++;
                            count--;
                            break;
                        }
                    }
                    maxi = max(maxi, count);
                }
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};