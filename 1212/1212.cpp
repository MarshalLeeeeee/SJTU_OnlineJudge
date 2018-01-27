#include <stdio.h>

using namespace std;

struct Node
{
    long long left;
    long long right;
    long long parent;
    long long weight;
    Node(void): parent(0){}
};
long long num;
Node t[100001];
Node root;
Node node_queue[100001];
long long node_queue_head = 0, node_queue_tail = 0;
void pre_print(Node &n)
{
    printf("%lld ", n.weight);
    if(n.left) pre_print(t[n.left]);
    if(n.right) pre_print(t[n.right]);
}

int main()
{
    scanf("%lld", &num);
    long long index;
    for(index = 1; index <= num; index++)
    {
        scanf("%lld", &t[index].left); //printf("%lld ", t[index].left);
        scanf("%lld", &t[index].right); //printf("%lld ", t[index].right);
        scanf("%lld", &t[index].weight); //printf("%lld\n", t[index].weight);
    }
    if(num == 1)
    {
        printf("%lld", t[1].weight);
        return 0;
    }
    for(index = 1; index <= num; index++)
    {
        if(t[index].left) t[t[index].left].parent = index;
        if(t[index].right) t[t[index].right].parent = index;
    }
    for(index = 1; index <= num; index++)
        if(!t[index].parent) {root = t[index]; break;}
    node_queue[node_queue_tail++] = root;
    long long index1, index2;
    while(node_queue_head != node_queue_tail)
    {
        index1 = node_queue_head;
        index2 = node_queue_tail;
        for(;index1 < index2; index1++)
        {
            printf("%lld ", node_queue[index1].weight);
            if(node_queue[index1].left) node_queue[node_queue_tail++] = t[node_queue[index1].left];
            if(node_queue[index1].right) node_queue[node_queue_tail++] = t[node_queue[index1].right];
            node_queue_head++;
        }
    }
    return 0;
}
