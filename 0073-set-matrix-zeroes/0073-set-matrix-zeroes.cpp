class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool first_row_zero = false;
        bool first_col_zero = false;

        // Check if the first row contains any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row_zero = true;
                break;
            }
        }

        // Check if the first column contains any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }

        // Use first row and first column to mark zeros for the rest of the matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0; // Fix: use 'j' here instead of 'i'
                }
            }
        }

        // Zero out submatrix based on marks in first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out first row if needed
        if (first_row_zero) { // Fix: variable name match (snake_case)
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero out first column if needed
        if (first_col_zero) { // Fix: variable name match (snake_case)
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};