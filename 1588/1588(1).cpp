#include <iostream>
#include <cstdio>
using namespace std;
int n;
int data[1000001];
int stack[1000001];
int tail = 0;
int binary_index(int value)
{
    int left = 1, right = tail, mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(stack[mid] > value) left = mid + 1;
        else if(stack[mid] < value) right = mid - 1;
        else return mid;
    }
    return left;
}
int main()
{
    scanf("%d", &n);
    for(int index = 1; index <= n; index++) scanf("%d", &data[index]);
    for(int index = 1, pos; index <= n; index++)
    {
        pos = binary_index(data[index]);
        if(pos > tail) stack[++tail] = data[index];
        else stack[pos] = data[index];
    }
    printf("%d\n", tail);
    tail = 0;
    for(int index = n, pos; index >= 1; index--)
    {
        pos = binary_index(data[index]);
        if(pos > tail) stack[++tail] = data[index];
        else stack[pos] = data[index];
    }
    printf("%d\n", tail);
    return 0;
}
