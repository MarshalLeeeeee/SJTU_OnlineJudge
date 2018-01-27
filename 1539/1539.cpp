#include <iostream>
#include <cstdio>
using namespace std;
int len, cnt = 1, ans = 0;
int pos[15] = {0};
bool visited[15];
bool check(int row, int col)
{
    //return true if in the same angle
    for(int index = 1; index <= row; index++)
    {
        if(pos[index] == row + col - index || pos[index] == col - row + index) return 1;
    }
    return 0;
}
void dfs(void)
{
    if(cnt <= len)
    {
        for(int index = 1; index <= len; index++)
        {
            if(!visited[index] && !check(cnt, index))
            {
                visited[index] = 1;
                pos[cnt] = index;
                cnt++;
                if(cnt > len)
                {
                    ans++;
                    if(ans <= 3)
                    {
                        for(int index2 = 1; index2 <= len; index2++)
                            printf("%d ", pos[index2]);
                        puts("");
                    }
                }
                dfs();
                cnt--;
                pos[cnt] = 0;
                visited[index] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d", &len);
    dfs();
    printf("%d", ans);
    return 0;
}
