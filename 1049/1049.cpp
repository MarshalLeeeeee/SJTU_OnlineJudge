#include <stdio.h>

using namespace std;

int stack_deep;
int seq[1000];
int train_num;
int train_stack[1000];
int stack_tail = 0;


int main()
{
    int num;
    int flag;
    scanf("%d", &num);
    int index, index2, index3;
    for(index = 0; index < num; index++)
    {
        scanf("%d", &train_num);
        scanf("%d", &stack_deep);
        for(index2 = 0; index2 < train_num; index2++)
        {
            scanf("%d", &seq[index2]);
        }

        index2 = 0;//record the "in_stack"
        index3 = 0;//record the seq of out
        flag = 0;
        stack_tail = 0;
        while(index3 < train_num)
        {
            if(stack_tail)//priority of the train_stack
            {
                if(train_stack[stack_tail-1] == seq[index3]){stack_tail--; index3++; continue;}
                else
                {
                    if(index2 >= train_num)
                    {
                        printf("NO\n");
                        flag = 1;
                        break;
                    }
                }
            }

            while(index2 < train_num && index2 != seq[index3])//still exist train that goes in
            {
                if(stack_tail != stack_deep)//the stack is not full
                {
                    train_stack[stack_tail++] = index2++;
                }
                else// not the head of in_stack and train_stack and the wait stack if full
                {
                    printf("NO\n");
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
            else {index2++; index3++;}
        }
        if(!flag) printf("YES\n");
    }
    return 0;
}
