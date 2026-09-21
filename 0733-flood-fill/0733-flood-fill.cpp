class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {  int m = image.size(); 
        int n = image[0].size(); 
        
        int startingColor = image[sr][sc];
         if (startingColor == color) {
            return image;
        }
    //vector<int>vis(m,vector<int>(0));
        queue<pair<int,int>> q; 
        q.push({sr, sc}); 
        image[sr][sc] = color; 
        while(!q.empty()){
             auto it = q.front();
             q.pop();
             int r=it.first;
             int c=it.second;
                // 1. Check DOWN
            if (r + 1 < m && image[r + 1][c] == startingColor) {
                image[r + 1][c] = color;
                q.push({r + 1, c});
            }
            
            // 2. Check UP
            if (r - 1 >= 0 && image[r - 1][c] == startingColor) {
                image[r - 1][c] = color;
                q.push({r - 1, c});
            }
            
            // 3. Check RIGHT
            if (c + 1 < n && image[r][c + 1] == startingColor) {
                image[r][c + 1] = color;
                q.push({r, c + 1});
            }
             if (c - 1 >= 0 && image[r][c - 1] == startingColor) {
                image[r][c - 1] = color;
                q.push({r, c - 1});
            }
        }return image;
    }
};