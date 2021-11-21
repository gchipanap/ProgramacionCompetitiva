#include <iostream>
#include <stdio.h>

using namespace std;
int i,j,k;
int x,y,counts;
int map[102][102];
char temp;
int main()
{
	while(cin >> x >> y)
	{
		for(i = 0; i < 102; i++)
			for(j = 0; j < 102; j++)
				map[i][j] = 0;
		for(i = 1; i <= x; i++)
		{
			for(j = 1; j <= y; j++)
			{
				cin >> tmp;
				if (temp == '.')
					map[i][j] = 0;
				else if (temp == 'T')
					map[i][j] = -1;
			}
		}
		for(i = x; i > 0; i--)
		{
			for(j = y; j > 0; j--)
			{
				if(map[i][j] == -1)
					if(map[i+1][j] == 0 || map[i-1][j] == 0 || map[i][j+1] == 0 || map[i][j-1] == 0)
						map[i][j] = 1;
			}
		}
		counts = 1;
		for(k = 1; counts != 0; k++)
		{
			for(counts = 0, i = x; i > 0; i--)
				for(j = y; j > 0; j--)
				{
					if(map[i][j] == -1)
					{
						counts++;
						if(map[i+1][j] == 0 || map[i-1][j] == k || map[i][j+1] == k || map[i][j-1] == k)
							map[i][j] = k + 1;
					}
				}
		}
		for(i = 1; i <= x; i++)
		{
			for(j = 1; j <= y; j++)
			{
				if(map[i][j] == 0)
				{
					if(k > 10)
						std::cout<<"...";
					else
						std::cout<<"..";
				}
				else 
				{
					if(k > 10)
					{
						if(map[i][j] < 10)
							std::cout<<".."<<map[i][j];
						else
							std::cout<<"."<<map[i][j];
					}
					else
						std::cout<<"."<<map[i][j];
				}
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}