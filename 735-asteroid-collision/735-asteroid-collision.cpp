class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> collisionStack;
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            if (collisionStack.empty()) {
                collisionStack.push(asteroids.at(i));
                continue;
            }
            if (asteroids.at(i) > 0 && collisionStack.top() > 0) {
                collisionStack.push(asteroids.at(i));
            }
            if (asteroids.at(i) < 0 && collisionStack.top() < 0) {
                collisionStack.push(asteroids.at(i));
            }
            if (asteroids.at(i) > 0 && collisionStack.top() < 0) {
                collisionStack.push(asteroids.at(i));
            }
            if (asteroids.at(i) < 0 && collisionStack.top() > 0) {
                while (true) {
                    if (collisionStack.empty()) {
                        collisionStack.push(asteroids.at(i));
                        break;
                    }
                    if (collisionStack.top() < 0) {
                        collisionStack.push(asteroids.at(i));
                        break;
                    }
                    if (abs(collisionStack.top()) == abs(asteroids.at(i))) {
                        collisionStack.pop();
                        break;
                    }

                    if (abs(collisionStack.top()) > abs(asteroids.at(i)))
                        break;
                    if (abs(collisionStack.top()) < abs(asteroids.at(i)))
                        collisionStack.pop();
                }
            }
        }
        while (!collisionStack.empty()) {
            ans.push_back(collisionStack.top());
            collisionStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};