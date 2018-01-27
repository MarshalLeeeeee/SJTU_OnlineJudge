#include <iostream>
#include <cstdio>
using namespace std;
int n, a, b;
int data[10001];
char order[10];
bool over_flag;
void add(int pos, int value)
{
    for(int index = pos; index <= n; index += (index & -index))
    {
        data[index] += value;
    }
}
int sum(int pos)
{
    int ans = 0;
    for(int index = pos; index; index -= (index & -index))
    {
        ans += data[index];
    }
    return ans;
}
int main()
{
    over_flag = 1;
    scanf("%d", &n);
    for(int index = 1; index <= n; index++) data[index] = 0;
    for(int index = 1, tmp; index <= n; index++)
    {
        scanf("%d", &tmp);
        add(index, tmp);
    }
    while(over_flag)
    {
        cin >> order;
        switch(order[0])
        {
        case 'q':
            {
                scanf("%d %d", &a, &b);
                printf("%d\n", sum(b)-sum(a-1));
                break;
            }
        case 'd':
            {
                scanf("%d %d", &a, &b);
                add(a, -b);
                break;
            }
        case 'i':
            {
                scanf("%d %d", &a, &b);
                add(a, b);
                break;
            }
        case 'e':
            {
                over_flag = 0;
                break;
            }
        }
    }
    return 0;
}
