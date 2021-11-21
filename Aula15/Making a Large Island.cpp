class Solution {
public:
	int largestIsland(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<int> vCount(2,0);
		int number = 2;               
		int maxNum = 1;                
		for (int i = 0; i<grid.size(); i++)
			for (int j = 0; j<grid[i].size(); j++)    
				if (grid[i][j] == 1)
				{
					int others = 0;
					int count = 0;
					fun(grid,vCount, count, i, j, number,others);
					number++;
					vCount.push_back(count);
					maxNum = max(maxNum, count + others+1);
				}
		if(maxNum>n*n)
			return n*n;
		else
			return maxNum;
	}
	void fun(vector<vector<int>>& grid, vector<int>& vCount, int& count, int i, int j, int& number,int& others) {
		if (i<0 || i==grid.size() || j<0 || j==grid.size() || grid[i][j] > 1) return;
		if (grid[i][j] == 0) {
			int up(0), down(0), left(0),temp(0);  
			if (i > 0 && grid[i - 1][j] != number) {
				temp += vCount[grid[i - 1][j]];   
				up = grid[i - 1][j];
			}
			if (i < grid.size() - 1 && grid[i + 1][j] != number&&grid[i + 1][j] != up) {
				temp += vCount[grid[i + 1][j]];  
				down = grid[i + 1][j];
			}
			if (j > 0 && grid[i][j - 1] != number&&grid[i][j - 1] != up&&grid[i][j - 1] != down) {
				temp += vCount[grid[i][j - 1]];   
				left = grid[i][j - 1];
			}
			if (j < grid.size() - 1 && grid[i][j + 1] != number&&grid[i][j + 1] != up&&grid[i][j + 1] != down&&g[i][j + 1] != left) 
				temp += vCount[grid[i][j + 1]];
			others = max(others, temp);
			return;
		}
		grid[i][j] = number;
		count++;
		fun(grid, vCount, count, i - 1, j, number,others);
		fun(grid, vCount, count, i + 1, j, number, others);
		fun(grid, vCount, count, i, j - 1, number, others);
		fun(grid, vCount, count, i, j + 1, number, others);
	}
};
