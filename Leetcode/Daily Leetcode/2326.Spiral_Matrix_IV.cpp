class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res (m, vector<int>(n, -1));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        //0: east, 1: south, 2: west, 3: north

        int i = 0, j = 0; //current position

        int currentDirection = 0; //east

        ListNode* current = head;
        while (current != NULL) {
            //assgin first then do the update later
            
            res[i][j] = current->val;
            current = current->next;

            int nextI = i + directions[currentDirection][0];
            int nextJ = j + directions[currentDirection][1];

            if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || res[nextI][nextJ] != -1) {
                currentDirection = (currentDirection + 1) % 4;
            }

            i += directions[currentDirection][0];
            j += directions[currentDirection][1];
        }
        return res;
    }
};