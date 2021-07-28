class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> tmpQueue;
        int arr[26];
        for(int i=0;i<26;i++) {
            arr[i] = 0;
        }

        for(int i=0;i<s.length();i++) {
            arr[s.at(i) - 'a'] += 1;
            tmpQueue.push(s.at(i));
        }
        char ans = '#';
        int pos = -1;
        int j = 0;
        while(!tmpQueue.empty()) {
            if(arr[tmpQueue.front() - 'a'] > 1) {
                j++;
                tmpQueue.pop();
                continue;
            }
            pos = j;
            ans = tmpQueue.front();
            break;
        }
        return pos;
    }
};