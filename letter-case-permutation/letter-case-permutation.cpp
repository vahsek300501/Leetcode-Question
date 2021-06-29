class Solution {
public:
    vector<string> letterCase;

    void getAllLetterCasePermutations(string s, int cnt) {
        if (cnt >= s.length()) {
            letterCase.push_back(s);
            return;
        }
        int asciiVal = (int) s.at(cnt);
        if ((asciiVal >= 65 && asciiVal <= 90) || (asciiVal >= 97 && asciiVal <= 122)) {
            char tmp = s.at(cnt);
            tmp = tolower(tmp);
            s.at(cnt) = tmp;
            getAllLetterCasePermutations(s, cnt + 1);

            tmp = toupper(tmp);
            s.at(cnt) = tmp;
            getAllLetterCasePermutations(s, cnt + 1);
        } else {
            getAllLetterCasePermutations(s,cnt+1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        getAllLetterCasePermutations(s,0);
        return letterCase;
    }
};