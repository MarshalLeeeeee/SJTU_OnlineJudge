#include <stdio.h>
using namespace std;

int num, order_num;
int candy[500001];
int candy_num[500001];
int max_num;
char op[3];
int x, y;
bool flag = 0;
void c_operate(int x, int y)
{
    int x_root = x, y_root = y;
    while(candy[x_root] > 0) x_root = candy[x_root];
    while(candy[y_root] > 0) y_root = candy[y_root];
    if(candy[x_root] == 0 || candy[y_root] == 0) return ;
    if(x_root == y_root) return ;
    if(candy[x_root] < candy[y_root]) // x tree has more elements
    {
        candy_num[-1*candy[x_root]]--;
        candy[x_root] += candy[y_root];
        candy_num[-1*candy[x_root]]++;
        candy_num[-1*candy[y_root]]--;
        candy[y_root] = x_root;
        if(-1*candy[x_root] > max_num) max_num = -1*candy[x_root];
    }
    else
    {
        candy_num[-1*candy[y_root]]--;
        candy[y_root] += candy[x_root];
        candy_num[-1*candy[y_root]]++;
        candy_num[-1*candy[x_root]]--;
        candy[x_root] = y_root;
        if(-1*candy[y_root] > max_num) max_num = -1*candy[y_root];
    }
}
void d_operate(int x)
{
    int x_root = x, tmp;
    while(candy[x_root] > 0) {tmp = candy[x_root]; candy[x_root] = 0; x_root = tmp;}
    candy_num[-1*candy[x_root]]--;
    if(max_num == -1*candy[x_root] && candy_num[-1*candy[x_root]] == 0)
    {
        int index;
        for(index = max_num; index >= 1; index--)
        {
            if(candy_num[index]) break;
        }
        max_num = index;
    }
    candy[x_root] = 0;
}
int q_operate(int x)
{
    int cnt = 0;
    for(int index = max_num; index >= 1; index--)
    {
        if(candy_num[index])
            cnt+=candy_num[index];
        if(cnt >= x) return index;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &num, &order_num);
    for(int index = 1; index <= num; index++)
        candy[index] = -1;
    for(int index = 0; index <= num; index++)
        candy_num[index] = 0;
    candy_num[1] = num;
    max_num = 1;
    while(order_num--)
    {
        scanf("%s %d", op, &x);
        switch(op[0])
        {
        case 'C':
            {
                scanf("%d", &y);
                c_operate(x, y);
                flag = 0;
                break;
            }
        case 'Q':
            {
                printf("%d\n", q_operate(x));
                break;
            }
        case 'D':
            {
                d_operate(x);
                flag = 0;
                break;
            }
        }
    }
    return 0;
}
