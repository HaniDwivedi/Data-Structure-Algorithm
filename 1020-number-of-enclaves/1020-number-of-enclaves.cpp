class Solution {
private: 
      int solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        int cnt = 0;
        bool bnd = false;
        
        queue<pair<int, int>> q;
        q.push({i, j}); 
        vis[i][j] = 1;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            auto it = q.front();
            int r = it.first;
            int c = it.second;
            q.pop();
            
            cnt++;
            
            if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
                bnd = true;
            }
          
            for (int d = 0; d < 4; d++) {
                int nrow = r + delRow[d];
                int ncol = c + delCol[d];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            } 
            
        }
     
        if (bnd == true) {
            return 0; 
        }
        
        return cnt; 
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int temp = solve(grid, vis, i, j);
                    cnt += temp;
                }
            }
        }
        return cnt;
    }
};
