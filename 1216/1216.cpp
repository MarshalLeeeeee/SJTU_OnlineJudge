#include <iostream>
#include <cstdio>
using namespace std;
int order_num, a, b;
char order[20];
int minHeap[20001];
int tail = 0;
void ins(int a)
{
    if(tail == 0) minHeap[++tail] = a;
    else
    {
        int curr = ++tail;
        while(curr > 1)
        {
            if(a < minHeap[curr/2])
            {
                minHeap[curr] = minHeap[curr/2];
                curr /= 2;
            }
            else break;
        }
        minHeap[curr] = a;
    }
}
int fnd(int a)
{
    int mininum;
    int index;
    for(index = 1; index <= tail; index++)
    {
        if(minHeap[index] > a) {mininum = minHeap[index]; break;}
    }
    for(int index2 = index + 1; index2 <= tail; index2++)
    {
        if(minHeap[index2] > a && minHeap[index2] < mininum) {index = index2; mininum = minHeap[index2];}
    }
    return index;
}
void dcs(int a, int b)
{
    minHeap[a] -= b;
    int curr = a, tmp;
    while(curr>1)
    {
        if(minHeap[curr] < minHeap[curr/2])
        {
            tmp = minHeap[curr/2];
            minHeap[curr/2] = minHeap[curr];
            minHeap[curr] = tmp;
            curr /= 2;
        }
        else break;
    }
}
int main()
{
    scanf("%d", &order_num);
    for(int index = 0; index < order_num; index++)
    {
        cin >> order;
        switch(order[0])
        {
        case 'i':
            {
                scanf("%d", &a);
                ins(a);
                break;
            }
        case 'f':
            {
                scanf("%d", &a);
                printf("%d\n", fnd(a));
                break;
            }
        case 'd':
            {
                scanf("%d %d", &a, &b);
                dcs(a, b);
                break;
            }
        }
    }
    return 0;
}
