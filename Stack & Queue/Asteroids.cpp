class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int left = 0;
        int right = 0;
        while (right < asteroids.size()) {
            if (right <= left) {
                // right is next to left
                right++;
                continue;
            }
            if (asteroids[left] == 0) {
                left++;
                continue;
            }
            if (asteroids[left] > 0 && asteroids[right] < 0) {
                // diff direction
                if (asteroids[left] < -asteroids[right]) {
                    // explode left
                    asteroids[left] = 0;
                    while (asteroids[left] == 0 && left > 0) {
                        left--;
                    }
                } else if (asteroids[left] == -asteroids[right]) {
                    // explode left
                    asteroids[left] = 0;
                    while (asteroids[left] == 0 && left > 0) {
                        left--;
                    }
                    // explode right              
                    asteroids[right] = 0;
                    right++;
                } else if (asteroids[left] > 0) {
                    // explode right
                    asteroids[right] = 0;
                    right++;
                }

                // save some time 
                if (left == 0 && asteroids[left] == 0) {
                    left = right;
                    right++;
                }
            } else {
                // same direction
                left++;
                right++;
            }
        }
        vector<int> out;
        for (const auto& v : asteroids) {
            if (v != 0) {
                out.push_back(v);
            }
        }
        return out;
    }
};