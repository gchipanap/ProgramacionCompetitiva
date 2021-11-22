class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> arr(m, vector<int>(n,0));
        arr[0][0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (obstacleGrid[i][j] == 1 || (i == 0 && j == 0)) 
                    continue;
                else 
                    arr[i][j] = (i > 0 ? arr[i-1][j] : 0) + (j > 0 ? arr[i][j-1] : 0);
        return arr[m-1][n-1];
    }
};