#include <iostream>
#include <stdio.h>

using namespace std;

int height;
int stat[1001][1001];
int route[1001][1001] = {0};
/*
int max_route(int x, int y)
{
    if(x == height)
    {
        route[x][y] = stat[x][y];
        return stat[x][y];
    }
    else
    {
        route[x][y] = max_int(route[x+1][y], route[x+1][y+1]) + stat[x][y];
        return route[x][y];
    }
}
*/
int max_int(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    scanf("%d", &height);
    int index, index2;
    for(index = 1; index <= height; index++)
    {
        for(index2 = 1; index2 <= index; index2++)
        {
            scanf("%d", &stat[index][index2]);
        }
    }

    for(index = height; index >= 1; index--)
    {
        for(index2 = 1; index2 <= index; index2++)
        {
            if(index == height) route[index][index2] = stat[index][index2];
            else
            {
                route[index][index2] = max_int(route[index+1][index2], route[index+1][index2+1]) + stat[index][index2];
            }
        }
    }

    cout << route[1][1];
    return 0;
}
