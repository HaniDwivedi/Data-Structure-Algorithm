class Solution {
private:
    vector<pair<int,int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return; // Fixed: removed the 0
        }
        
        grid[i][j] = '$';
        
        for(pair<int,int>& p_dir : dir) { // Fixed: added ' : dir'
            int ni = i + p_dir.first;     // Fixed: renamed variable for clarity
            int nj = j + p_dir.second;    // Fixed: spelling of 'second'
            dfs(grid, ni, nj);            // Fixed: passing the correct new coordinates
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};