#include <stdio.h>
using namespace std;
int data[51][51][5000];
int len[50][50];
int k, height;
void print(int *ans, int len)
{
    for(int index= len - 1; index >= 0; index--) printf("%d", ans[index]);
}
void add(int *ans, int &len, long long value)
{
    int index, digit, x = 0, tmp;
    for(index = 0; index < len && value > 0; index++)
    {
        digit = value % 10;
        value /= 10;
        tmp = (digit + ans[index] + x);
        ans[index] = tmp % 10;
        x = tmp / 10;
    }
    while(value)
    {
        digit = value % 10;
        value /= 10;
        tmp = (digit + x);
        ans[len++] = tmp % 10;
        x = tmp / 10;
    }
    if(x) ans[len++] = 1;
}
void add(int *ans, int &len, int *value, int value_len)
{
    int index, digit, x = 0, tmp;
    for(index = 0; index < value_len && index < len; index++)
    {
        tmp = (ans[index] + value[index] + x);
        digit = tmp % 10;
        x = tmp / 10;
        ans[index] = digit;
    }
    while(index < len)
    {
        tmp = (ans[index] + x);
        digit = tmp % 10;
        x = tmp / 10;
        ans[index++] = digit;
    }
    while(index < value_len)
    {
        tmp = (value[index] + x);
        digit = tmp % 10;
        x = tmp / 10;
        ans[len++] = digit;
        index++;
    }
    if(x) ans[len++] = 1;
}

int main()
{
    int index1, index2, index3;
    scanf("%d %d", &k, &height);

    for(index1 = 1; index1 <= height; index1++)
    {
        for(index2 = 0; index2 < k; index2++)
        {
            data[index1][index2][0] = 0; len[index1][index2] = 1;
            if(index1 == 1) add(data[index1][index2], len[index1][index2], k-index2);
            else
            {
                for(index3 = 0; index3 < k - index2; index3++)
                {
                    add(data[index1][index2], len[index1][index2], data[index1-1][index3], len[index1-1][index3]);
                }
            }
        }
    }
    print(data[height - 1][0], len[height - 1][0]);putchar('\n');
    return 0;
}
