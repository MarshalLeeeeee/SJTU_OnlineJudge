#include <iostream>
#include <cstdio>
#define A_MOD 1009
#define B_MOD 1000003
#define abs(x) (x) > (-x) ? (x) : (-x)
#define step(start, index) (start + index * index)
using namespace std;
struct Node
{
    int data;
    int times;
    Node(void):times(0){}
};
Node hash_data[4][1000];
Node sum[1000000];
int cnt = 0, num;
void ins(Node *arr, int value, int len, int mod, int add)
{
    int tmp = abs(value);
    int start = tmp % mod;
    int index;
    for(index = 0; ; index++)
    {
        if(!arr[step(start, index) % len].times)
        {
            arr[step(start, index) % len].data = value;
            arr[step(start, index) % len].times += add;
            return ;
        }
        if(arr[step(start, index) % len].data == value)
        {
            arr[step(start, index) % len].times += add;
            return ;
        }
    }
}
int fnd(Node *arr, int value, int len, int mod)
{
    int tmp = abs(value);
    int start = tmp % mod;
    int index;
    for(index = 0; ; index++)
    {
        if(!arr[step(start, index) % len].times) return 0;
        if(value + arr[step(start, index) % len].data == 0) return arr[step(start, index) % len].times;
    }
}
int main()
{
    int tmp, index1, index2, index3;
    scanf("%d", &num);
    for(index1 = 0; index1 < num; index1++)
    {
        for(index2 = 0; index2 < 4; index2++)
        {
            scanf("%d", &tmp);
            ins(hash_data[index2], tmp, 1000, A_MOD, 1);
        }
    }
    for(index1= 0; index1 < 1000; index1++)
    {
        if(!hash_data[0][index1].times) continue;
        for(index2 = 0; index2 < 1000; index2++)
        {
            if(!hash_data[1][index2].times) continue;
            ins(sum, hash_data[0][index1].data + hash_data[1][index2].data, 1000000, B_MOD, hash_data[0][index1].times * hash_data[1][index2].times);
        }
    }
    for(index1= 0; index1 < 1000; index1++)
    {
        if(!hash_data[2][index1].times) continue;
        for(index2 = 0; index2 < 1000; index2++)
        {
            if(!hash_data[3][index2].times) continue;
            cnt += fnd(sum, hash_data[2][index1].data + hash_data[3][index2].data, 1000000, B_MOD) * hash_data[2][index1].times * hash_data[3][index2].times;
        }
    }
    printf("%d", cnt);
    return 0;
}
