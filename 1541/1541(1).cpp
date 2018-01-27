#include <iostream>
#include <cstdio>
using namespace std;
int window, len;
int data[200000];
int seq_q[200000];
int head = 0;
int tail = -1;
int main()
{
    scanf("%d %d", &window, &len);
    for(int index = 0; index < len; index++) scanf("%d", &data[index]);
    for(int index = 0; index < window-1; index++)
    {
        while(tail >= head && seq_q[tail] < data[index]) tail--;
        seq_q[++tail] = data[index];
    }
    for(int index = window-1; index < len; index++)
    {
        while(tail >= head && seq_q[tail] < data[index]) tail--;
        seq_q[++tail] = data[index];
        printf("%d ", seq_q[head]);
        if(data[index+1-window] == seq_q[head]) head++;
    }
    return 0;
}
