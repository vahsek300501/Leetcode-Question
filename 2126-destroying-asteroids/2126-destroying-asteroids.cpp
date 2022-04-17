class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long int tmpMass = mass;
        for(int i = 0;i<asteroids.size();i++) {
            if(tmpMass < asteroids.at(i))
                return false;
            tmpMass = tmpMass + asteroids.at(i);
        }
        return true;
    }
};