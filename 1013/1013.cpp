#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int v, n;
int volumn[1000];
int price[1000];
int max_price[10001];

int max_int(int a, int b)
{
    return (a > b ? a: b);
}

int main()
{
    scanf("%d", &v);
    scanf("%d", &n);
    int index, index2;
    for(index = 0; index < n; index++)
    {
        scanf("%d", &volumn[index]);
        scanf("%d", &price[index]);
    }
    memset(max_price, 0, sizeof(max_price));

    for(index = 0; index < n; index++)
    {
        for(index2 = 0; index2 <= v; index2++)
        {
            if(index2 - volumn[index] < 0) continue;
            else
            {
                max_price[index2] = max_int(max_price[index2], max_price[index2-volumn[index]] + price[index]);
            }
        }
    }
    cout << max_price[v];
    return 0;
}
