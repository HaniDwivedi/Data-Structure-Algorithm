class Solution {
public:
    int cnt = 0;

    void solve(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int m = grid.size();
        int n = grid[0].size();

        int size = q.size();
        bool rottedAny = false;

        // while loop queue ke size ke liye
        int k = 0;
        while (k < size) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            // TOP check
            if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                q.push({r - 1, c});
                grid[r - 1][c] = 2;
                rottedAny = true;
            }

            // BOTTOM check
            if (r + 1 < m && grid[r + 1][c] == 1) {
                q.push({r + 1, c});
                grid[r + 1][c] = 2;
                rottedAny = true;
            }

            // LEFT check
            if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                q.push({r, c - 1});
                grid[r][c - 1] = 2;
                rottedAny = true;
            }

            // RIGHT check
            if (c + 1 < n && grid[r][c + 1] == 1) {
                q.push({r, c + 1});
                grid[r][c + 1] = 2;
                rottedAny = true;
            }

            k++;
        }

        if (rottedAny == true)
            cnt++;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        cnt = 0; // Reset count for multiple test cases

        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    freshCount++;
            }
        }

        if (freshCount == 0) return 0;

        while (!q.empty()) {
            solve(grid, q);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return cnt;
    }
};