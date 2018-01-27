#include <iostream>
#include <cstdio>
#define INF 10000000
using namespace std;
int vertice, edge, start, dest, curr, total_cost;
struct Edge
{
    int v;
    int weight;
    Edge *next;
    Edge(void):next(NULL){}
};
struct Vertice
{
    Edge *head;
    Edge *tail;
    Vertice(void){head = new Edge; tail = head;}
};
struct Dest
{
    int point;
    int distance;
    int num;
    Dest(void):num(1){}
    Dest(int p, int d, int n):point(p), distance(d), num(n){}
    Dest &operator=(const Dest &other){point = other.point; distance = other.distance; num = other.num; return *this;}
    bool operator<(const Dest &other){return (distance < other.distance) || (distance == other.distance && num < other.num); }
};
Dest minHeap[200001];int heap_tail = 0;
Vertice graph[10001];
int cost[10001];
int prevv[10001];
bool visited[10001];
int num[10001];
void push(Dest &d)
{
    heap_tail++;
    int curr = heap_tail;
    while(curr>1)
    {
        if(d < minHeap[curr/2]) {minHeap[curr] = minHeap[curr/2]; curr /= 2;}
        else {minHeap[curr] = d; return ;}
    }
    minHeap[1] = d;
}
Dest pop(void)
{
    Dest ans = minHeap[1], tmp;
    if(heap_tail == 1) {heap_tail--; return ans;}
    minHeap[1] = minHeap[heap_tail--];
    int curr = 1;
    while(curr * 2 <= heap_tail)
    {
        if(curr * 2 + 1 <= heap_tail)
        {
            if(minHeap[curr*2] < minHeap[curr] || minHeap[curr*2+1] < minHeap[curr])
            {
                if(minHeap[curr*2] < minHeap[curr*2+1])
                {
                    tmp = minHeap[curr];
                    minHeap[curr] = minHeap[curr*2];
                    minHeap[curr*2] = tmp;
                    curr *= 2;
                }
                else
                {
                    tmp = minHeap[curr];
                    minHeap[curr] = minHeap[curr*2+1];
                    minHeap[curr*2+1] = tmp;
                    curr = curr*2 + 1;
                }
            }
            else break;
        }
        else
        {
            if(minHeap[curr*2] < minHeap[curr])
            {
                tmp = minHeap[curr];
                minHeap[curr] = minHeap[curr*2];
                minHeap[curr*2] = tmp;
                curr *= 2;
            }
            else break;
        }
    }
    return ans;
}
void show(void)
{
    int anti_route[10001], total_cost = 0;
    int curr = dest, index;
    for(index = 1; index <= 10000; index++)
    {
        anti_route[index] = curr;
        if(curr == start) break;
        curr = prevv[curr];
    }
    printf("%d\n", cost[dest]);
    for(int index2 = index; index2 >= 1; index2--) printf("%d ", anti_route[index2]);
}
int main()
{
    scanf("%d %d %d %d", &vertice, &edge, &start, &dest);
    if(edge == 0) {printf("%d\n%d", 0, start);return 0;}
    for(int index = 1, tmp; index <= edge; index++)
    {
        Edge *new_edge = new Edge;
        scanf("%d", &tmp);
        scanf("%d %d", &new_edge->v, &new_edge->weight);
        graph[tmp].tail->next = new_edge;
        graph[tmp].tail = new_edge;
    }
    for(int index = 1; index <= vertice; index++) {cost[index] = INF; num[index] = INF; visited[index] = 0; prevv[index] = 0;}
    prevv[start] = 0; cost[start] = 0; visited[start] = 1; num[start] = 1; curr = start;
    Dest ans;
    while(curr != dest)
    {
        Edge *tmp = graph[curr].head;
        while(tmp->next)
        {
            if(cost[curr] + tmp->next->weight < cost[tmp->next->v] || (cost[curr] + tmp->next->weight == cost[tmp->next->v] && num[curr] + 1 < num[tmp->next->v]))
            {
                cost[tmp->next->v] = cost[curr] + tmp->next->weight;
                prevv[tmp->next->v] = curr;
                num[tmp->next->v] = num[curr] + 1;
                Dest dd(tmp->next->v, cost[tmp->next->v], num[tmp->next->v]);
                push(dd);
            }
            tmp = tmp->next;
        }
        ans = pop();
        while(visited[ans.point]) ans = pop();
        curr = ans.point;
        visited[ans.point] = 1;
    }
    show();
    return 0;
}
