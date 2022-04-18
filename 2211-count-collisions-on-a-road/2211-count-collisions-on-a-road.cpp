class Solution {
public:
    int countCollisions(string directions) {
        stack<char> collisionStack;
        int countCollision = 0;
        for (char &direction : directions) {
            if (collisionStack.empty()) {
                collisionStack.push(direction);
                continue;
            } else if (direction == 'L' && collisionStack.top() == 'R') {
                countCollision += 2;
                collisionStack.pop();
                while (!collisionStack.empty() && collisionStack.top() == 'R') {
                    countCollision++;
                    collisionStack.pop();
                }
                collisionStack.push('S');
            } else if (direction == 'L' && collisionStack.top() == 'S') {
                countCollision++;
            } else if (direction == 'R') {
                collisionStack.push('R');
            } else if (direction == 'S') {
                while (!collisionStack.empty() && collisionStack.top() == 'R') {
                    countCollision++;
                    collisionStack.pop();
                }
                collisionStack.push('S');
            } else {
                collisionStack.push(direction);
            }
        }
        return countCollision;
    }
};