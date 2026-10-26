#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        
        q.push({i, j});
        grid[i][j] = 1; // Mark starting cell as visited (blocked)
        
        // Push marker (-1, -1) to signify the end of the current distance layer
        q.push({-1, -1});

        int cnt = 1;
        bool isN = false; // Tracks if any valid neighbor was added in current layer

        vector<int> dx = {1, 0, -1, 0, -1, -1, 1, 1};
        vector<int> dy = {0, -1, 0, 1, 1, -1, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Layer delimiter reached
            if (r == -1 && c == -1) {
                if (isN && !q.empty()) {
                    cnt++;        // Advance to next layer count
                    isN = false;  // Reset flag for the new layer
                    q.push({-1, -1}); // Push marker for the upcoming layer
                }
                continue;
            }

            // Target reached
            if (r == m - 1 && c == n - 1) {
                return cnt;
            }

            // Explore 8 directions
            for (int l = 0; l < 8; l++) {
                int a = r + dx[l];
                int b = c + dy[l];

                // Check bounds and unvisited clear path cell (0)
                if (a >= 0 && b >= 0 && a < m && b < n && grid[a][b] == 0) {
                    q.push({a, b});
                    grid[a][b] = 1; // Mark visited immediately to prevent cycles
                    isN = true;     // Flag that valid neighbors were added
                }
            }
        }

        return -1; // Path not found
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;

        return bfs(grid, 0, 0);
    }
};