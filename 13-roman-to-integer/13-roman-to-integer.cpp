class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        int number = 0;
        int i = 0;
        while (i < (int) s.length()) {
            if (s[i] == 'I') {
                if (i + 1 < (int) s.length() && s[i + 1] == 'V') {
                    number += 4;
                    i += 2;
                } else if (i + 1 < (int) s.length() && s[i + 1] == 'X') {
                    number += 9;
                    i += 2;
                } else {
                    number += umap[s[i]];
                    i += 1;
                }
            } else if (s[i] == 'X') {
                if (i + 1 < (int) s.length() && s[i + 1] == 'L') {
                    number += 40;
                    i += 2;
                } else if (i + 1 < (int) s.length() && s[i + 1] == 'C') {
                    number += 90;
                    i += 2;
                } else {
                    number += umap[s[i]];
                    i += 1;
                }
            } else if (s[i] == 'C') {
                if (i + 1 < (int) s.length() && s[i + 1] == 'D') {
                    number += 400;
                    i += 2;
                } else if (i + 1 < (int) s.length() && s[i + 1] == 'M') {
                    number += 900;
                    i += 2;
                } else {
                    number += umap[s[i]];
                    i += 1;
                }
            } else {
                number += (umap[s[i]]);
                i++;
            }
        }
        return number;
    }
};