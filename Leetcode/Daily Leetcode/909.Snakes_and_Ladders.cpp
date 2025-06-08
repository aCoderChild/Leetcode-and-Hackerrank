class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int moves = 0;

        while (!q.empty()) {
            int size = q.size(); // all the possible cases
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) return moves;

                for (int dice = 1; dice <= 6; ++dice) {
                    int next = curr + dice;
                    if (next > n * n) continue;

                    vector<int> pos = getCoordinates(next, n);
                    int r = pos[0], c = pos[1];

                    // If there's a snake or ladder, use it
                    if (board[r][c] != -1) {
                        next = board[r][c];
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }

        return -1; // not reachable
    }

private:
    // Maps a square number to (row, col) on the board
    vector<int> getCoordinates(int num, int n) {
        int row = (num - 1) / n;
        int col = (num - 1) % n;

        int actualRow = n - 1 - row; // bottom to top
        int actualCol = (row % 2 == 0) ? col : (n - 1 - col); // left-right alternation

        return {actualRow, actualCol};
    }
};