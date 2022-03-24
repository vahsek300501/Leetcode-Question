class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        int count = 0;
        while(i<=j) {
            if(i == j) {
                count++;
                break;
            }
            if(people.at(i) + people.at(j) <= limit) {
                count++;
                i++;
                j--;
            } else {
                count++;
                j--;
            }
        }
        return count;
    }
};