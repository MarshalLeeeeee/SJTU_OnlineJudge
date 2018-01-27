#include <stdio.h>
using namespace std;
struct Node
{
    int x;
    int y;
    int value;
};
Node data[10001];
int col[100000];
int row[100000];
int num, order_num, op, a, b;
int main(void)
{
    scanf("%d", &num);
    for(int index = 0; index < num; index++)
        scanf("%d %d %d", &data[index].x, &data[index].y, &data[index].value);
    for(int index = 0; index < 100000; index++){col[index] = index; row[index] = index;}
    scanf("%d", &order_num);
    for(int index = 0; index < order_num; index++)
    {
        scanf("%d %d %d", &op, &a, &b);
        switch(op)
        {
        case 0:
            {
                int tmp;
                tmp = row[a];
                row[a] = row[b];
                row[b] = tmp;
                break;
            }
        case 1:
            {
                int tmp;
                tmp = col[a];
                col[a] = col[b];
                col[b] = tmp;
                break;
            }
        case 2:
            {
                int flag = 0;
                for(int index = 0; index < num; index++)
                {
                    if(data[index].x == row[a] && data[index].y == col[b])
                    {
                        flag = 1;
                        printf("%d\n", data[index].value);
                        break;
                    }
                }
                if(!flag) printf("0\n");
                break;
            }
        }
    }
    return 0;
}
