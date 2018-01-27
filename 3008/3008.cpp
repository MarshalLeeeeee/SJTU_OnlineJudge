#include <iostream>
#include <cstdio>
using namespace std;
int n, m, route;
int startx, starty, endx, endy, nextx, nexty;
char map[102][102];
bool visited[102][102];
int step[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
struct Point
{
    int x, y;
    Point(void){}
    Point(int xx, int yy):x(xx), y(yy){}
};
Point q[10005];
int tail = -1, head = 0;

int main()
{
    scanf("%d %d", &n, &m);while(getchar() != '\n') continue;
    scanf("%d %d %d %d", &startx, &starty, &endx, &endy);while(getchar() != '\n') continue;
    for(int index1 = 1; index1 <= n; index1++)
    {
        for(int index2 = 1; index2 <= m; index2++)
        {
            scanf("%c", &map[index1][index2]);
        }
        while(getchar() != '\n') continue;
    }
    for(int index1 = 0; index1 <= n+1; index1++)
        map[index1][0] = map[index1][m+1] = '*';
    for(int index2 = 0; index2 <= m+1; index2++)
        map[0][index2] = map[n+1][index2] = '*';
    tail++; q[tail].x = startx; q[tail].y = starty;
    visited[startx][starty] = 1;
    route = -1;
    while(tail >= head)
    {
        route++;
        int index1 = head, index2 = tail;
        int x, y;
        for( ; index1 <= index2; index1++)
        {
            x = q[index1].x; y = q[index1].y;
            if(x == endx && y == endy) {printf("%d", route); return 0;}
            switch(map[x][y])
            {
            case '.':
                {
                    for(int index3 = 0; index3 <= 1; index3++)
                    {
                        nextx = x + step[index3][0];
                        nexty = y + step[index3][1];
                        if((map[nextx][nexty] == '|' || map[nextx][nexty] == '.') && !visited[nextx][nexty])
                        {
                            tail++; q[tail].x = nextx; q[tail].y = nexty;
                            visited[nextx][nexty] = 1;
                        }
                    }
                    for(int index3 = 2; index3 <= 3; index3++)
                    {
                        nextx = x + step[index3][0];
                        nexty = y + step[index3][1];
                        if((map[nextx][nexty] == '-' || map[nextx][nexty] == '.') && !visited[nextx][nexty])
                        {
                            tail++; q[tail].x = nextx; q[tail].y = nexty;
                            visited[nextx][nexty] = 1;
                        }
                    }
                    break;
                }
            case '-':
                {
                    for(int index3 = 2; index3 <= 3; index3++)
                    {
                        nextx = x + step[index3][0];
                        nexty = y + step[index3][1];
                        if((map[nextx][nexty] == '-' || map[nextx][nexty] == '.') && !visited[nextx][nexty])
                        {
                            tail++; q[tail].x = nextx; q[tail].y = nexty;
                            visited[nextx][nexty] = 1;
                        }
                    }
                    break;
                }
            case '|':
                {
                    for(int index3 = 0; index3 <= 1; index3++)
                    {
                        nextx = x + step[index3][0];
                        nexty = y + step[index3][1];
                        if((map[nextx][nexty] == '|' || map[nextx][nexty] == '.') && !visited[nextx][nexty])
                        {
                            tail++; q[tail].x = nextx; q[tail].y = nexty;
                            visited[nextx][nexty] = 1;
                        }
                    }
                    break;
                }
            }
            head++;
        }
    }
    printf("-1");
    return 0;
}
