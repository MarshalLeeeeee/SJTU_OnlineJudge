#include <stdio.h>
using namespace std;
int test_num;
int data[6][6], state[6][6], visit[6][6];
int startx, starty, endx, endy, currx, curry;
int step[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int total_cost = 0;
int ans;
void dfs(void)
{
    if(total_cost < ans)
    {
        if(currx == endx && curry == endy)
        {
            ans = total_cost;
            return ;
        }
        for(int index = 0; index < 4; index++)
        {
            if(currx + step[index][0] >= 6 || currx + step[index][0] < 0 || curry + step[index][1] >= 6 || curry + step[index][1] < 0 || visit[currx + step[index][0]][curry + step[index][1]]) continue;
            state[currx + step[index][0]][curry + step[index][1]] = (state[currx][curry] * data[currx + step[index][0]][curry + step[index][1]]) % 4 + 1;
            total_cost += state[currx][curry] * data[currx + step[index][0]][curry + step[index][1]];
            currx += step[index][0]; curry += step[index][1];
            visit[currx][curry] = 1;
            dfs();
            visit[currx][curry] = 0;
            currx -= step[index][0]; curry -= step[index][1];
            total_cost -= state[currx][curry] * data[currx + step[index][0]][curry + step[index][1]];
        }
    }
}
void dfs(int x, int y, int sum, int status)
{
    if(sum < ans)
    {
        if(x == endx && y == endy)
        {
            ans = sum;
            return ;
        }
        for(int index = 0; index < 4; index++)
        {
            int nextx = x + step[index][0];
            int nexty = y + step[index][1];
            if(!visit[nextx][nexty]
               && nextx >= 0 && nextx < 6
               && nexty >= 0 && nexty < 6)
            {
                int cost = data[nextx][nexty] * status;
                visit[nextx][nexty] = 1;
                dfs(nextx, nexty, sum+cost, cost%4+1);
                visit[nextx][nexty] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d", &test_num);
    for(int index = 0; index < test_num; index++)
    {
        for(int index1 = 0; index1 < 6; index1++)
        {
            for(int index2 = 0; index2 < 6; index2++)
            {
                scanf("%d", &data[index1][index2]);
                //state[index1][index2] = 0;
                visit[index1][index2] = 0;
            }
        }
        scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
        //state[startx][starty] = 1; visit[startx][starty] = 1;
        //currx = startx; curry = starty;
        ans = 1000000;
        //total_cost = 0;
        dfs(startx, starty, 0, 1);
        printf("%d\n", ans);
    }
    return 0;
}
