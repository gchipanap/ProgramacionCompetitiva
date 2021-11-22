class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        constexpr int kInf = 1e6;
    for (int i = 1; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j) {
        int m = kInf;
        for (int k = 0; k < grid[0].size(); ++k) {
          if (k == j) continue;
          m = min(m, grid[i - 1][k]);
        }
        grid[i][j] += m;
    }
    return *min_element(begin(grid.back()), end(grid.back()));
  }
};