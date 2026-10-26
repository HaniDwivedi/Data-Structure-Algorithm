class Solution {
public:
long bfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
      long sum = 0;
        q.push({i, j});
        sum += grid[i][j];
        grid[i][j] = 0;

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, -1, 0, 1};
        while (!q.empty()) {

            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for (int l = 0; l < 4; l++) {
                int a = r + dx[l];
                int b = c + dy[l];
                if (a < 0 || b < 0 || a >= m || b >= n || grid[a][b] == 0)
                    continue;
                q.push({a, b});
                sum += grid[a][b];
                grid[a][b] = 0;
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                   long s = bfs(grid, i, j);
                   long p=k;
                    if (s % p== 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};