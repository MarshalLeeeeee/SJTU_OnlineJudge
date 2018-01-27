#include <iostream>
#include <stdio.h>

using namespace std;

int stat[60] = {0};
int a, b;
long long len;

int main()
{
    cin >> a >> b >> len;
    stat[1] = 1; stat[2] = 1;
    long long index;
    long long loop = len + 1;
    for(index = 3; index <= len; index++)
    {
        stat[index] = (a * stat[index-1] + b * stat[index-2]) % 7;
        if(stat[index] == 1 && stat[index-1] == 1){loop = index-2;break;}
    }
    if(loop == 1)
    {
        cout << 1;
        return 0;
    }
    len = len % loop;
    if(len == 0)
    {
        cout << stat[loop];
        return 0;
    }
    for(index = 3; index <= len; index++)
    {
        stat[index] = (a * stat[index-1] + b * stat[index-2]) % 7;
    }
    cout << stat[len];
    return 0;
}
