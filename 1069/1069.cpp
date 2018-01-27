#include <stdio.h>
#include <cstring>
using namespace std;
int n, m;
int value[101];
int num[101];
bool price[100001];
int usenum[100001];
int give_ans(int n, int m)
{
    price[0] = 1;
    for(int index1 = 0; index1 < n; index1++)
    {
        for(int index2 = 0; index2 <= m; index2++) usenum[index2] = 0;
        for(int index2 = 1; index2 <= m; index2++)
        {
            if(price[index2]) continue;
            if(price[index2-value[index1]] && usenum[index2-value[index1]] < num[index1])
            {
                price[index2] = 1;
                usenum[index2] = usenum[index2-value[index1]] + 1;
            }
        }
    }
    int ans = 0;
    for(int index = 1; index <= m; index++)
    {

        if(price[index]) ans++;
    }
    return ans;
}
int main()
{
    scanf("%d %d", &n, &m);
    while(n != 0 || m != 0)
    {
        int index;
        for(index = 0; index < n; index++)
            scanf("%d", &value[index]);
        for(index = 0; index < n; index++)
            scanf("%d", &num[index]);
        for(index = 0; index <= m; index++) price[index] = 0;
        printf("%d\n", give_ans(n, m));
        scanf("%d %d", &n, &m);
    }
    return 0;
}
