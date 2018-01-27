#include <stdio.h>
#include <iostream>
#define M 1009
#define N 1000003
#define INF 10000001
#define abs(x) (x) > (-x) ? (x) : (-x)
using namespace std;
struct Node
{
    int data;
    int times;
    Node(void):times(0){}
};
Node hash_data[4][1000];
Node sum[1000000];
int num;
int cnt = 0;

void ins(int x, Node *arr, int m, int len, int add = 1)
{
    int y = abs(x);
    int index, start = y % m;
    for(index = 0; ; index++)
    {
        if(!arr[(start + index*index) % len].times)
        {
            arr[(start + index*index) % len].data = x;
            arr[(start + index*index) % len].times += add;
            break;
        }
        if(arr[(start + index*index) % len].data == x)
        {
            arr[(start + index*index) % len].times += add;
            break;
        }
    }
}
int fnd(int x, Node *arr, int m, int len)
{
    int y = abs(x);
    int start = y % m;
    int index;
    for(index = 0; ; index++)
    {
        if(!arr[(start + index * index) % len].times) return 0;
        if(x + arr[(start + index * index) % len].data == 0) return arr[(start + index * index) % len].times;
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
            ins(tmp, hash_data[index2], M, 1000);
        }
    }
    for(index1 = 0; index1 < 1000; index1++)
    {
        if(!hash_data[0][index1].times) continue;
        for(index2 = 0; index2 < 1000; index2++)
        {
            if(!hash_data[1][index2].times) continue;
            ins(hash_data[0][index1].data+hash_data[1][index2].data, sum, N, 1000000, hash_data[0][index1].times*hash_data[1][index2].times);
        }
    }
    for(index3 = 0; index3 < 1000000; index3++)
    {
        if(sum[index3].times) cout << sum[index3].data << ' ' << sum[index3].times << endl;
    }
    for(index1 = 0; index1 < 1000; index1++)
    {
        if(!hash_data[2][index1].times) continue;
        for(index2 = 0; index2 < 1000; index2++)
        {
            if(!hash_data[3][index2].times) continue;
            //int haha = fnd(hash_data[2][index1].data+hash_data[3][index2].data, sum, N, 1000000) * hash_data[2][index1].times * hash_data[3][index2].times;
            //if(haha) {cout << index1 << ' ' << index2 << endl;}
            cnt += fnd(hash_data[2][index1].data+hash_data[3][index2].data, sum, N, 1000000) * hash_data[2][index1].times * hash_data[3][index2].times;
        }
    }
    printf("%d", cnt);
    return 0;
}
