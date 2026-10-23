class Solution {
public:
    int m, n, ans = 0;

    void dfs(vector<vector<int>>& grid, int i, int j,int &temp) {
       
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] !=1) return;  
        
 temp++;
      
        grid[i][j] = -1;
        dfs(grid, i + 1, j,temp);
        dfs(grid, i - 1, j,temp);
        dfs(grid, i, j + 1,temp);
        dfs(grid, i, j - 1,temp);

        ans = max(ans, temp);
    
}

    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {  int temp = 0;
            if (grid[i][j] == 1) {
                dfs(grid, i, j,temp);
            }
        }
    }
    return ans;
}
}
;