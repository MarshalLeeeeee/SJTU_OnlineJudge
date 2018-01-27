#include <stdio.h>
using namespace std;
long long count_num = 0;
long long num_num;
long long search_num;
struct Node
{
    long long data;
    Node *next;
    Node(void):next(NULL){}
    Node(long long x):data(x),next(NULL){}
};

class staticTable
{
public:
    Node *head;
    Node *tail;

    staticTable(void)
    {
        head = new Node;
        tail = head;
    }
    void push(long long value)
    {
        Node *tmp = new Node(value);
        tail->next = tmp;
        tail = tmp;
    }
    void search_node(long long value)
    {
        Node *index;
        for(index = head; index -> next != NULL; index = index->next)
        {
            count_num++;
            if(value == index->next->data)
            {
                if(index == head) break;
                else
                {
                    Node *tmp;
                    tmp = head->next;
                    head->next = index->next;
                    index->next = index->next->next;
                    head->next->next = tmp;
                    break;
                }
            }
        }
    }
};

int main()
{
    long long index;
    long long d;
    staticTable st;
    scanf("%lld", &num_num);
    for(index =0 ; index < num_num; index++)
    {
        scanf("%lld", &d);
        st.push(d);
    }
    scanf("%lld", &search_num);
    for(index = 0; index < search_num; index++)
    {
        scanf("%lld", &d);
        st.search_node(d);
    }
    printf("%lld", count_num);
    return 0;
}
