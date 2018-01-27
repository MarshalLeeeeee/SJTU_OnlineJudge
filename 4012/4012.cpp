#include <stdio.h>
using namespace std;
long long minHeap[10001];
long long minHeap_len = 0;
long long heap_sum = 0;
long long num;
long long total_cost = 0;
long long last_cost = 0;
void push(long long value)
{
    long long pos = ++minHeap_len;
    while(pos > 1)
    {
        if(value < minHeap[pos / 2])
        {
            minHeap[pos] = minHeap[pos/2];
            pos /= 2;
        }
        else
        {
            minHeap[pos] = value;
            return ;
        }
    }
    minHeap[pos] = value;
    return ;
}
void pop(void)
{
    minHeap[1] = minHeap[minHeap_len--];
    long long pos = 1;
    long long tmp;
    while(pos * 2 <= minHeap_len)//have son
    {
        if(pos * 2 + 1 <= minHeap_len)//have right son
        {
            if(minHeap[pos*2] <= minHeap[pos*2+1] && minHeap[pos*2] <= minHeap[pos])
            {
                tmp = minHeap[pos];
                minHeap[pos] = minHeap[pos*2];
                minHeap[pos*2] = tmp;
                pos = pos * 2;
            }
            else if(minHeap[pos*2+1] <= minHeap[pos*2] && minHeap[pos*2+1] <= minHeap[pos])
            {
                tmp = minHeap[pos];
                minHeap[pos] = minHeap[pos*2+1];
                minHeap[pos*2+1] = tmp;
                pos = pos * 2 + 1;
            }
            else
            {
                return ;
            }
        }
        else
        {
            if(minHeap[pos*2] < minHeap[pos])
            {
                tmp = minHeap[pos];
                minHeap[pos] = minHeap[pos*2];
                minHeap[pos*2] = tmp;
            }
            pos = pos * 2;
        }
    }
}
void adjust(long long value)
{
    minHeap[1] = value;
    long long pos = 1;
    long long tmp;
    while(pos * 2 <= minHeap_len)//have son
    {
        if(pos * 2 + 1 <= minHeap_len)//have right son
        {
            if(minHeap[pos*2] <= minHeap[pos*2+1] && minHeap[pos*2] <= minHeap[pos])
            {
                tmp = minHeap[pos];
                minHeap[pos] = minHeap[pos*2];
                minHeap[pos*2] = tmp;
                pos = pos * 2;
            }
            else if(minHeap[pos*2+1] <= minHeap[pos*2] && minHeap[pos*2+1] <= minHeap[pos])
            {
                tmp = minHeap[pos];
                minHeap[pos] = minHeap[pos*2+1];
                minHeap[pos*2+1] = tmp;
                pos = pos * 2 + 1;
            }
            else
            {
                return ;
            }
        }
        else
        {
            if(minHeap[pos*2] < minHeap[pos])
            {
                tmp = minHeap[pos];
                minHeap[pos] = minHeap[pos*2];
                minHeap[pos*2] = tmp;
            }
            pos = pos * 2;
        }
    }
}
int main()
{
    long long index, d;
    scanf("%lld", &num);
    for(index = 0; index < num; index++)
    {
        scanf("%lld", &d);
        push(d);
    }
    while(minHeap_len > 2)
    {
        last_cost = 0;
        if(minHeap[2] < minHeap[3]) last_cost = minHeap[1] + minHeap[2];
        else last_cost = minHeap[1] + minHeap[3];
        total_cost += last_cost;
        pop();
        adjust(last_cost);
    }
    total_cost += minHeap[1] + minHeap[2];
    printf("%lld", total_cost);
    return 0;
}
