#include <iostream>
#include <cstdio>
using namespace std;
int window_size, len;
int arr[200000];
int seq_stack[200000];
int tail = -1, head = 0;

int main()
{
    scanf("%d", &window_size);
    scanf("%d", &len);
    for(int index = 0; index < len; index++)
        scanf("%d", &arr[index]);
    for(int index = 0; index < window_size - 1; index++)
    {
        while(tail >= 0 && seq_stack[tail] < arr[index]) tail--;
        seq_stack[++tail] = arr[index];
    }
    for(int index = window_size - 1; index < len; index++)
    {
        while(tail >= head && seq_stack[tail] < arr[index]) tail--;
        seq_stack[++tail] = arr[index];
        printf("%d ", seq_stack[head]);
        if(arr[index-window_size+1] == seq_stack[head]) head++;
    }
    return 0;
}
