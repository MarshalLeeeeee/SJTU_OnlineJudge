#include <iostream>
#include <cstdio>
using namespace std;
struct Edge
{
    int in, out;
    int weight;
    bool operator<(const Edge &other){return weight < other.weight;}
    bool operator<=(const Edge &other){return weight <= other.weight;}
    bool operator>(const Edge &other){return weight > other.weight;}
    bool operator>=(const Edge &other){return weight >= other.weight;}
    Edge &operator=(const Edge &other){in = other.in; out = other.out; weight = other.weight;return *this;}
};
Edge edge_set[100001];
int vertice_set[10001];
int vertice, edge;
int total_weight = 0;
void quick_sort(int ibegin, int iend)
{
    if(ibegin >= iend) return ;
    Edge pivot = edge_set[ibegin], tmp;
    int left, right;
    for(left = ibegin; left <= iend; left++)
    {
        if(pivot < edge_set[left]) break;
    }
    for(right = left+1; right <= iend; right++)
    {
        if(pivot > edge_set[right])
        {
            tmp = edge_set[right];
            edge_set[right] = edge_set[left];
            edge_set[left] = tmp;
            left++;
        }
    }
    edge_set[ibegin] = edge_set[left-1];
    edge_set[left-1] = pivot;
    quick_sort(ibegin, left-2);
    quick_sort(left, iend);
}
int return_root(int x)
{
    int curr_x = x;
    while(vertice_set[curr_x] > 0) curr_x = vertice_set[curr_x];
    return curr_x;
}
bool together(int x, int y)
{
    // if is in the same tree, return 1;
    // otherwise, return 0;
    return return_root(x) == return_root(y);
}
void comb(int x, int y)
{
    int root_x = return_root(x);
    int root_y = return_root(y);
    if(root_x != root_y)
    {
        if(vertice_set[root_x] < vertice_set[root_y])
        {
            vertice_set[root_x] += vertice_set[root_y];
            vertice_set[root_y] = root_x;
        }
        else
        {
            vertice_set[root_y] += vertice_set[root_x];
            vertice_set[root_x] = root_y;
        }
    }
}
int main()
{
    scanf("%d %d", &vertice, &edge);
    for(int index = 1; index <= edge; index++)
        scanf("%d %d %d", &edge_set[index].in, &edge_set[index].out, &edge_set[index].weight);
    for(int index = 1; index <= vertice; index++) vertice_set[index] = -1;
    quick_sort(1, edge);
    int pos = 1;
    for(int index = 0; index < vertice - 1; index++)
    {
        while(together(edge_set[pos].in, edge_set[pos].out)) pos++;
        total_weight += edge_set[pos].weight;
        comb(edge_set[pos].in, edge_set[pos].out);
    }
    printf("%d", total_weight);
    return 0;
}
