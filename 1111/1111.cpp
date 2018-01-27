#include <stdio.h>

using namespace std;
struct Node
{
    int left;
    int right;
    char ch;
    int i;
    Node(){}
    Node(char c):ch(c){}
};
Node t[27];
char pre[27];
int pre_len = 1;
char mid[27];
int mid_len = 1;
char seq[1001];
Node node_queue[1001];
int head = 0, tail = 0;

void analysis(int pre_start, int pre_end, int mid_start, int mid_end)
{
    if(pre_start == pre_end) return ;
    if(pre_start + 1 == pre_end)
    {
        Node tmp(pre[pre_start]);
        tmp.left = 0;
        tmp.right = 0;
        t[pre_start] = tmp;
        return ;
    }
    int d;
    int i;
    Node tmp(pre[pre_start]);
    for(i = mid_start; i < mid_end; i++)
    {
        if(mid[i] == pre[pre_start]) break;
    }
    d = i - mid_start;

    if(d == 0)
    {
        tmp.left = 0;
        tmp.right = pre_start + 1;
    }
    else if(d == pre_end - pre_start - 1)
    {
        tmp.left = pre_start + 1;
        tmp.right = 0;
    }
    else
    {
        tmp.left = pre_start + 1;
        tmp.right = pre_start + 1 + d;
    }

    t[pre_start] = tmp;

    analysis(pre_start + 1, pre_start + 1 + d, mid_start, mid_start + d);
    analysis(pre_start + 1 + d, pre_end, mid_start + 1 + d, mid_end);
}

int main()
{
    int index;
    for(index = 1; index<=1000; index++)
    {
        seq[index] = '@';
    }
    char tmp;
    for(; pre_len <= 1000; pre_len++)
    {
        tmp = getchar();
        if(tmp != '\n')
        {
            pre[pre_len] = tmp;
        }
        else break;
    }
    for(; mid_len <= 1000; mid_len++)
    {
        tmp = getchar();
        if(tmp != '\n')
        {
            mid[mid_len] = tmp;
        }
        else break;
    }

    analysis(1, pre_len, 1, mid_len);

    seq[1] = t[1].ch;
    node_queue[tail++] = t[1];
    node_queue[0].i = 1;
    int index1, index2;
    while(head != tail)
    {
        index1 = head; index2 = tail;
        for(; index1 != index2; index1++)
        {
            if(node_queue[index1].left)
            {
                node_queue[tail++] = t[node_queue[index1].left];
                node_queue[tail - 1].i = 2 * node_queue[index1].i;
                seq[2 * node_queue[index1].i] = t[node_queue[index1].left].ch;
            }
            if(node_queue[index1].right)
            {
                node_queue[tail++] = t[node_queue[index1].right];
                node_queue[tail - 1].i = 2 * node_queue[index1].i + 1;
                seq[2 * node_queue[index1].i + 1] = t[node_queue[index1].right].ch;
            }
            head++;
        }
    }
    int count;
    for(index = 1, count = 1; index <= 1000, count < pre_len;index++)
    {
        if(seq[index] == '@') printf("NULL ");
        else {printf("%c ", seq[index]); count++;}
    }
    return 0;
}
