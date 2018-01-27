#include <stdio.h>
using namespace std;

struct Node
{
    long long left;
    long long right;
    long long parent;
    Node(void):parent(0){}
};
long long num;
Node t[100001];
Node root;
Node node_queue[100001];
long long node_queue_head = 0, node_queue_tail = 0;
long long len;

int main(void)
{
    scanf("%lld", &num);
    if(num == 1)
    {
        printf("Y");
        return 0;
    }
    long long index;
    for(index = 1; index <= num; index++)
    {
        scanf("%lld", &t[index].left);
        scanf("%lld", &t[index].right);
    }
    for(index = 1; index <= num; index++)
    {
        if(t[index].left) t[t[index].left].parent = index;
        if(t[index].right) t[t[index].right].parent = index;
    }
    for(index = 1; index <= num; index++)
    {
        if(!t[index].parent){root = t[index];break;}
    }
    node_queue[node_queue_tail++] = root;
    len = node_queue_tail - node_queue_head;

    long long index1, index2;
    int flag = 1;
    while(node_queue_head != node_queue_tail)
    {
        index1 = node_queue_head;
        index2 = node_queue_tail;
        for(;index1 != index2; index1++)
        {
            if(node_queue[index1].left)
            {
                if(!flag) {printf("N");return 0;}
                node_queue[node_queue_tail++] = t[node_queue[index1].left];
            }
            else flag = 0;
            if(node_queue[index1].right)
            {
                if(!flag) {printf("N");return 0;}
                node_queue[node_queue_tail++] = t[node_queue[index1].right];
            }
            else flag = 0;
            node_queue_head++;
        }
    }
    printf("Y");
    return 0;
}
