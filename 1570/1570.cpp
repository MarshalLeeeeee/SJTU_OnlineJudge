#include <iostream>
#include <cstdio>
using namespace std;
int n, t;
long long tmp;
long long data[100001];
int return_pos(long long value)
{
    int left = 1, right = n, mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(data[mid] < value) left = mid + 1;
        else if(data[mid] > value) right = mid - 1;
        else return mid;
    }
    return right;
}
int main()
{
    scanf("%d %d", &n, &t);
    for(int index = 1; index <= n; index++) scanf("%lld", &data[index]);
    for(int index = 1; index <= t; index++)
    {
        scanf("%lld", &tmp);
        printf("%d\n", n - return_pos(tmp));
    }
    return 0;
}
