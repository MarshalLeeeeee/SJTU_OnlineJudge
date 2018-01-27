#include <stdio.h>
#define PRE 0
#define POST 1
using namespace std;

long long num;
long long data[1000000];
long long stack[1000000]; long long tail = 0;
long long binary_index(long long value)
{
    if(!tail) return tail;
    long long left = 0, right = tail - 1, mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(value > stack[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}

int main()
{
    int index;
    scanf("%lld", &num);
    for(index = 0; index < num; index++)
        scanf("%lld", &data[index]);

    long long target;
    for(index = 0; index < num; index++)
    {
        target = binary_index(data[index]);
        if(target == tail) stack[tail++] = data[index];
        else stack[target] = data[index];
    }
    printf("%d\n", tail);
    tail = 0;
    for(index = num - 1; index >= 0; index--)
    {
        target = binary_index(data[index]);
        if(target == tail) stack[tail++] = data[index];
        else stack[target] = data[index];
    }
    printf("%d\n", tail);
    return 0;
}
