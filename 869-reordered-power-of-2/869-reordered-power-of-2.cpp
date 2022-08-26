class Solution {
public:
    bool compareFreqMaps(unordered_map<long long int, unordered_map<long long int, int>> &firstMap,
                         unordered_map<long long int, int> &secondMap) {
        auto itr = firstMap.begin();
        while (itr != firstMap.end()) {
            // long long int num = itr->first;
            if (itr->second == secondMap)
                return true;
            itr++;
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        if(n == 1)
            return true;
        unordered_map<long long int, unordered_map<long long int, int>> numFreqMap;
        for (int i = 0; i <= 30; i++) {
            auto number = (long long int) pow(2, i);
            auto number2 = (long long int) pow(2, i);
            unordered_map<long long int, int> digitMap;
            while (number != 0) {
                long long int digit = number % 10;
                number = number / 10;
                if (digitMap.find(digit) != digitMap.end())
                    digitMap[digit] += 1;
                else
                    digitMap[digit] = (long long int) 1;
            }
            numFreqMap[number2] = digitMap;
        }
        unordered_map<long long int, int> numberMap;
        while (n != 0) {
            int digit = n % 10;
            n = n / 10;
            if (numberMap.find(digit) != numberMap.end())
                numberMap[digit] += 1;
            else
                numberMap[digit] = 1;
        }
        return compareFreqMaps(numFreqMap, numberMap);
    }
};