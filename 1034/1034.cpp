#include <stdio.h>
using namespace std;

int n, k;
int data[400001];
int down_stack[400000];
int head = 1, tail = 0;
int minimax;

int main()
{
    scanf("%d %d", &n, &k);
    for(int index = 1; index <= n; index++)
    {
        scanf("%d", &data[index]);
        data[index+n] = data[index];
    }
    for(int index = 1; index <= k; index++)
    {
        while(head <= tail && down_stack[tail] < data[index]) tail--;
        down_stack[++tail] = data[index];
    }
    minimax = down_stack[head];
    for(int index = k + 1; index <= 2 * n; index++)
    {
        if(data[index - k] == down_stack[head]) head++;
        while(head <= tail && down_stack[tail] < data[index]) tail--;
        down_stack[++tail] = data[index];
        if(down_stack[head] < minimax) minimax = down_stack[head];
    }
    printf("%d", minimax);
    return 0;
}
