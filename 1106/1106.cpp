#include <iostream>
#include <cstdio>
#define LEN 9
using namespace std;
int map[LEN + 1][LEN + 1] = {0};
int test_num;
int flag;
int cnt;
bool exam(int index1, int index2)
{
    int flagg = 1;
    for(int index = 1; index <= LEN; index++)
    {
        if(index != index1 && map[index][index2] == map[index1][index2]) {flagg = 0;}
    }
    for(int index = 1; index <= LEN; index++)
    {
        if(index != index2 && map[index1][index] == map[index1][index2]) {flagg = 0;}
    }
    if(!flagg) return 0;
    int a = (index1 - 1) / 3 * 3;
    int b = (index2 - 1) / 3 * 3;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(a+i != index1 && b+j != index2)
            {
                if(map[a+i][b+j] == map[index1][index2]) return 0;
            }
        }
    }
    return 1;
}
void dfs(int index1, int index2)
{
    if(cnt == 2) {return ;}
    if(cnt <= 1)
    {
        if(map[index1][index2])
        {
            if(index2 == 9)
            {
                if(index1 == 9) {cnt++;}
                else dfs(index1+1, 1);
            }
            else dfs(index1, index2+1);
        }
        else
        {
            for(int index = 1; index <= 9; index++)
            {
                map[index1][index2] = index;
                if(exam(index1, index2))
                {
                     if(index2 == 9)
                    {
                        if(index1 == 9) {cnt++;}
                        else dfs(index1+1, 1);
                    }
                    else dfs(index1, index2+1);
                }
               map[index1][index2] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d", &test_num);
    for(int index = 1; index <= test_num; index++)
    {
        for(int index1 = 1; index1 <= LEN; index1++)
        {
            for(int index2 = 1; index2 <= LEN; index2++)
            {
                map[index1][index2] = 0;
            }
        }
        flag = 1; cnt = 0;
        for(int index1 = 1; index1 <= LEN; index1++)
        {
            for(int index2 = 1; index2 <= LEN; index2++)
            {
                scanf("%d", &map[index1][index2]);
                if(map[index1][index2])
                {
                    if(flag && !exam(index1, index2)) {flag = 0;}
                }
            }
        }
        if(!flag) {printf("No\n"); continue;}
        dfs(1, 1);
        if(cnt == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
