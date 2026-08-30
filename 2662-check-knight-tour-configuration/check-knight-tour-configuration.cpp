class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int r, int c, int exp, int n) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != exp) {
            return false;
        }
        if (exp == n * n - 1) {
            return true;
        }
        return isvalid(grid, r + 2, c + 1, exp + 1, n) ||
               isvalid(grid, r + 2, c - 1, exp + 1, n) ||
               isvalid(grid, r - 2, c + 1, exp + 1, n) ||
               isvalid(grid, r - 2, c - 1, exp + 1, n) ||
               isvalid(grid, r + 1, c + 2, exp + 1, n) ||
               isvalid(grid, r + 1, c - 2, exp + 1, n) ||
               isvalid(grid, r - 1, c + 2, exp + 1, n) ||
               isvalid(grid, r - 1, c - 2, exp + 1, n);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isvalid(grid, 0, 0, 0, grid.size());
    }
};