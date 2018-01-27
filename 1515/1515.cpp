#include <iostream>
#define INF 3000
using namespace std;
struct Point
{
    int x;
    int y;
    int step;
    Point(int xx = 0, int yy = 0, int s = 0):x(xx), y(yy), step(s){}
};
Point start_to_store[1000000];
Point dest_to_store[1000000];
int visit_start[1002][1002] = {0};
int visit_dest[1002][1002] = {0};
int distant[1002][1002]={INF};
int mapp[1002][1002] = {0};
int nex[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(void)
{
    int m, n;
    cin >> m >> n;
    int index1, index2, k;
    int curr_x, curr_y;
    int starthead = 0, starttail = 0;
    int desthead = 0, desttail = 0;
    int minstep = INF;
    for(index1 = 1; index1 <= n; index1++)
    {
        for(index2 = 1; index2 <= m; index2++)
        {
            cin >> mapp[index1][index2];
            if(mapp[index1][index2] == 2)
            {
                Point start = Point(index1, index2, 0);
                start_to_store[starttail++] = start;
                visit_start[index1][index2] = 1;
            }
            if(mapp[index1][index2] == 3)
            {
                Point dest = Point(index1, index2, 0);
                dest_to_store[desttail++] = dest;
                visit_dest[index1][index2] = 1;
            }
        }
    }
    for(index1 = 0; index1 < n+2; index1++)
    {
        mapp[index1][0] = 1;
        mapp[index1][m+1] = 1;
    }
    for(index2 = 0; index2 < m+2; index2++)
    {
        mapp[0][index2] = 1;
        mapp[n+1][index2] = 1;
    }
    while(starthead!=starttail)
    {
        index1 = starthead;
        index2 = starttail;
        for(; index1 < index2; index1++)
        {
            for(k = 0; k < 4; k++)
            {
                curr_x = start_to_store[index1].x + nex[k][0];
                curr_y = start_to_store[index1].y + nex[k][1];
                if(mapp[curr_x][curr_y] != 1 && !visit_start[curr_x][curr_y])
                {
                    if(mapp[curr_x][curr_y] == 4)
                    {
                        distant[curr_x][curr_y] = start_to_store[index1].step+1;
                    }
                    Point tmp = Point(curr_x, curr_y, start_to_store[index1].step+1);
                    start_to_store[starttail++] = tmp;
                    visit_start[curr_x][curr_y] = 1;
                }
            }
            starthead++;
        }
    }
    while(desthead!=desttail)
    {
        index1 = desthead;
        index2 = desttail;
        for(; index1 < index2; index1++)
        {
            for(k = 0; k < 4; k++)
            {
                curr_x = dest_to_store[index1].x + nex[k][0];
                curr_y = dest_to_store[index1].y + nex[k][1];
                if(mapp[curr_x][curr_y] != 1 && !visit_dest[curr_x][curr_y])
                {
                    if(mapp[curr_x][curr_y] == 4)
                    {
                        distant[curr_x][curr_y] += dest_to_store[index1].step+1;
                        if(minstep > distant[curr_x][curr_y]) minstep = distant[curr_x][curr_y];
                    }
                    Point tmp = Point(curr_x, curr_y, dest_to_store[index1].step+1);
                    dest_to_store[desttail++] = tmp;
                    visit_dest[curr_x][curr_y] = 1;
                }
            }
            desthead++;
        }
    }
    cout << minstep;
    return 0;
}
