#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
bool map[502][502];//1 is continent, 0 is ocean
int step[4][2] = {{0,1}, {-1,0}, {1, 0}, {0, -1}};
int flag = 1, cnt = 0;
void dfs(int x, int y)
{
    map[x][y] = 0;
    for(int index1 = 0; index1 < 4; index1++)
    {
        if(map[x+step[index1][0]][y+step[index1][1]])
            dfs(x+step[index1][0], y+step[index1][1]);
    }
}
int main()
{
    int tmp;
    scanf("%d %d", &n, &m);
    for(int index1 = 1; index1 <= n; index1++)
    {
        for(int index2 = 1; index2 <= m; index2++)
        {
            scanf("%d", &tmp);
            if(!tmp) map[index1][index2] = 1;
            else map[index1][index2] = 0;
        }
    }
    while(flag)
    {
        flag = 0;
        for(int index1 = 1; index1 <= n; index1++)
        {
            for(int index2 = 1; index2 <= m; index2++)
            {
                if(map[index1][index2])
                {
                    flag = 1;
                    dfs(index1, index2);
                    cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
