class Solution {
public:
    string countOfAtoms(string formula) {
        // Recursively parse the formula
        unordered_map<string, int> finalMap = parseFormula(formula);

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }

    // Recursively parse the formula
    unordered_map<string, int> parseFormula(string& formula) {
        // Local variable
        unordered_map<string, int> currMap;
        string currAtom;
        string currCount;

        // Iterate until the end of the formula
        while (index < formula.length()) {
            // UPPERCASE LETTER
            if (isupper(formula[index])) {
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                currAtom = formula[index];
                currCount = "";
                index++;
            }

            // lowercase letter
            else if (islower(formula[index])) {
                currAtom += formula[index];
                index++;
            }

            // Digit. Concatenate the count
            else if (isdigit(formula[index])) {
                currCount += formula[index];
                index++;
            }

            // Left Parenthesis
            else if (formula[index] == '(') {
                index++;
                unordered_map<string, int> nestedMap = parseFormula(formula);
                for (auto& [atom, count] : nestedMap) {
                    currMap[atom] += count;
                }
            }

            // Right Parenthesis
            else if (formula[index] == ')') {
                // Save the last atom and count of nested formula
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                index++;
                string multiplier;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                return currMap;
            }
        }

        // Save the last atom and count
        if (!currAtom.empty()) {
            if (currCount.empty()) {
                currMap[currAtom] += 1;
            } else {
                currMap[currAtom] += stoi(currCount);
            }
        }

        return currMap;
    }

private:
    // Global variable
    int index = 0;
};