/*
P6. Dungeon master
https://open.kattis.com/problems/dungeon
*/

#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>

using namespace std;

char a[35][35][35];
int l,r,c;
int next_[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

struct Nodo
{
  int x;
  int y;
  int z;
  int step;
};

Nodo s,e,now,last;

int bfs()
{
  queue<Nodo> q;
  q.push(s);
  while(q.size())
  {
    now=q.front();
    if(now.x==e.x&&now.y==e.y&&now.z==e.z)
      return now.step;
    for(int i=0;i<6;i++)
    {
      last.x=now.x+next_[i][0];
      last.y=now.y+next_[i][1];
      last.z=now.z+next_[i][2];
      if(last.x>0&&last.x<=l&&last.y>0&&last.y<=r&&last.z>0&&last.z<=c&&a[last.x][last.y][last.z]!='#')
      {
          a[last.x][last.y][last.z]='#';
          last.step=now.step+1;
          q.push(last);
      }
    }
    q.pop();
  }
  return -1;
}

int main()
{
  while(~scanf("%d%d%d",&l,&r,&c))
  {
    if(l==0&&r==0&&c==0)
      break;
    for(int i=1;i<=l;i++)
    {
      for(int j=1;j<=r;j++)
      {
        for(int k=1;k<=c;k++)
        {
          scanf(" %c",&a[i][j][k]);
          if(a[i][j][k]=='S')
          {
            s.x=i;
            s.y=j;
            s.z=k;
            s.step=0;
          }
          if(a[i][j][k]=='E')
          {
            e.x=i;
            e.y=j;
            e.z=k;
          }
        }
      }
    }
    int ans = bfs();
    if(ans==-1)
      std::cout<<"Trapped!\n";
    else 
      std::cout<< "Escaped in" << ans << "minute(s).\n";
  }
  return 0;
}