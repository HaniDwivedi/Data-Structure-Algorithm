class Solution {
public:
    int solve(vector<vector<int>>& grid, int start_i, int start_j) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({start_i, start_j});
        grid[start_i][start_j] = -1; // Mark visited
        bool iscovered = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int a = it.first;
            int b = it.second;

            for (int k = 0; k < 4; ++k) {
                int nx = a + dx[k];
                int ny = b + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    iscovered = false;
                } else if (grid[nx][ny] == 0) {
                    grid[nx][ny] = -1; // Mark visited
                    q.push({nx, ny});
                }
            }
        }

        return iscovered ? 1 : 0;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt += solve(grid, i, j);
                }
            }
        }

        return cnt;
    }
};