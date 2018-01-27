#include <iostream>
#include <cstdio>
using namespace std;
int course_num, edge;
struct Node
{
    int num;
    Node *next;
    Node(void):next(NULL){}
};
struct Course
{
    Node *head, *tail;
    Course(void){head = new Node; tail = head;}
};
int term[10001];
Course scheme[10001];
int in_num[10001];
bool visited[10001];
int q[500000]; int head, tail;
int main()
{
    int a, b;
    scanf("%d %d", &course_num, &edge);
    if(edge == 0){printf("1"); return 0;}
    for(int index = 1; index <= course_num; index++) {term[index] = 0; in_num[index] = 0;}
    for(int index = 1; index <= edge; index++)
    {
        scanf("%d %d", &a, &b);
        in_num[a]++;
        Node *new_node = new Node;
        new_node->num = a;
        scheme[b].tail->next = new_node;
        scheme[b].tail = new_node;
    }

    for(int index = 1; index <= course_num; index++)
    {
        if(!in_num[index])
        {
            head = 0; tail = -1;
            Node *tmp;
            int round = 1;
            q[++tail] = index;
            visited[index] = 1;
            term[index] = 1;
            while(head <= tail)
            {
                for(int index2 = 1; index2 <= course_num; index2++) visited[index2] = 0;
                round++;
                int index2 = head, index3 = tail;
                for(; index2 <= index3; index2++)
                {
                    tmp = scheme[q[index2]].head;
                    while(tmp->next)
                    {
                        if(!visited[tmp->next->num]) {q[++tail] = tmp->next->num; visited[tmp->next->num] = 1;}
                        if(round > term[tmp->next->num]) term[tmp->next->num] = round;
                        tmp = tmp->next;
                    }
                    head++;
                }
            }
        }
    }
    int m = term[1];
    for(int index = 1; index <= course_num; index++)
    {
        if(m < term[index]) m = term[index];
    }
    printf("%d", m);
    return 0;
}
