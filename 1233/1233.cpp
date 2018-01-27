#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
    int value;
    Node *next;
    Node(void):next(NULL){}
    Node(int x):value(x), next(NULL){}
};
int node_num, edge_num, start, len, cnt = 0, ans = 0;
Node pointer[11];
bool visited[11] = {0};
int s[30]; int tail = 0;
void dfs(void)
{
    if(cnt < len)
    {
        Node *curr = &pointer[s[tail-1]];
        while(curr->next)
        {
            if(visited[curr->next->value]){curr = curr->next; continue;}
            s[tail++] = curr->next->value;
            visited[s[tail-1]] = 1;
            cnt++;
            if(cnt == len) ans++;
            dfs();
            cnt--;
            visited[s[tail-1]] = 0;
            tail--;
            curr = curr->next;
        }
    }
}

int main()
{
    int a, b;
    scanf("%d %d %d %d", &node_num, &edge_num, &start, &len);
    for(int index = 1; index <= node_num; index++) pointer[index].value = index;
    for(int index = 1; index <= edge_num; index++)
    {
        scanf("%d %d", &a, &b);
        Node *curr = &pointer[a];
        while(curr->next) curr = curr->next;
        curr->next = new Node(b);
    }
    s[tail++] = start;
    visited[start] = 1;
    dfs();
    printf("%d", ans);
    return 0;
}
