class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        int server = 0;
        queue<pair<int, int>> q;
        grid[i][j] = -1;
        q.push({i, j});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            server++;
            for (int k = 0; k < m; k++) {

                if (grid[ k][c] == 1) {
                    grid[ k][c] = -1;
                    q.push({ k, c});
                }
            }

            for (int k = 0; k < n; k++) {

                if (grid[r][ k] == 1) {
                    grid[r][ k] = -1;
                    q.push({r,  k});
                }
            }
        }
           return (server > 1)? server : 0;
          
    }

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    ans += bfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};