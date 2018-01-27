#include <iostream>
using namespace std;

int sx,sy,ex,ey,ans;
int dir[][2]={{-1,0},{1,0},{0,1},{0,-1}};
int visit[6][6];
int map[6][6];

void DFS(int x,int y,int sum,int statu)
{
    if(sum<ans)
    {
        if(x==ex&&y==ey)
        {
            ans=sum;
            return ;
        }
        for(int i=0;i<4;i++)
        {
            int nextx=x+dir[i][0];
            int nexty=y+dir[i][1];
            if(visit[nextx][nexty]&&nextx>=0&&nextx<6&&nexty>=0&&nexty<6)
            {
                int cost=statu*map[nextx][nexty];
                visit[nextx][nexty]=0;
                DFS(nextx,nexty,sum+cost,cost%4+1);
                visit[nextx][nexty]=1;
            }
        }
    }
}

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                cin>>map[i][j];
                visit[i][j]=1;
            }
        }
        cin>>sx>>sy>>ex>>ey;
        ans=1000000;
        DFS(sx,sy,0,1);
        cout<<ans<<endl;
    }
    return 0;
}
