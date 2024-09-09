class Solution {
    const int hash_constant = 60013;
    int hashCoordinates (int x, int y) {
    return x + hash_constant * y;
} 
public:
//use hash function
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }

        vector<vector<int>> directions = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> currentPosition = {0, 0};
        int maxDistanceSquare = 0;
        int currentDirection = 0; //0: north, 1: east, 2: south, 3: west

        for (auto command : commands) {
            if (command == -1) {
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }

            else if (command == - 2) {
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            vector<int> direction = directions[currentDirection];
            for (int step = 0; step < command; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if(obstacleSet.contains(hashCoordinates(nextX, nextY))) {
                    break;
                }
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquare = max(maxDistanceSquare, currentPosition[0] * currentPosition[0] + currentPosition[1] * currentPosition[1]);
        }
        return maxDistanceSquare;
    }
};