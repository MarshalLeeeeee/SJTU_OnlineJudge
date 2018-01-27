#include <stdio.h>
#include <iostream>
using namespace std;
int seq_stack[1001];
int tail = -1;
int num;
bool flag = 1;
int ans = 0;

int main()
{
    scanf("%d", &num);
    char str[10];fgets(str,10,stdin);
    char xxx;cin>>xxx;
    int tmp;
    for(int index = 0; index < num; index++)
    {
        scanf("%d", &tmp);cin>>xxx;
        if(flag)
        {
            if(tmp >= seq_stack[0]) {seq_stack[0] = tmp; tail = 0;}
            else {seq_stack[1] = tmp; tail = 1; flag = 0;}
        }
        else
        {
            if(tmp > seq_stack[tail])
            {
                if(tmp >= seq_stack[0])
                {
                    for(int index2 = tail; index2 >= 0; index2--)
                    {
                        ans += seq_stack[0] - seq_stack[index2];
                    }
                    seq_stack[0] = tmp; tail = 0;
                }
                else
                {
                    for(int index2 = tail; index2 >= 0; index2--)
                    {
                        if(tmp > seq_stack[index2]) { ans += tmp - seq_stack[index2]; seq_stack[index2] = tmp;}
                        else break;
                    }
                    seq_stack[++tail] = tmp;
                }
            }
            else seq_stack[++tail] = tmp;
        }
    }
    printf("%d", ans);
    return 0;
}
