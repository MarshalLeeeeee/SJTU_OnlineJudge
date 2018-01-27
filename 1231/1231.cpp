#include <stdio.h>
#include <iostream>
using namespace std;
struct Node
{
    int left, right, parent;
    Node(void):left(0), right(0), parent(0){}
};
int node_num;
int target_a, target_b;
int root;
Node *arr;
bool ans_flag = 0;
int ans;

void fnd(int x, int y, int r)
{
    int curr_x = x, curr_y = y;
    while(curr_x != r && arr[curr_x].parent) curr_x = arr[curr_x].parent;
    while(curr_y != r && arr[curr_y].parent) curr_y = arr[curr_y].parent;
    if(curr_x == r && curr_y == r) {ans_flag = 1; ans = r;}
}
void post_check(int x, int y, int r)
{
    if(!ans_flag && r)
    {
        post_check(x, y, arr[r].left);
        post_check(x, y, arr[r].right);
        if(!ans_flag) fnd(x, y, r);
    }
}

int main()
{
    scanf("%d %d %d", &node_num, &target_a,  &target_b);
    arr = new Node[node_num+1];
    for(int index = 1; index <= node_num; index++)
        scanf("%d %d", &arr[index].left, &arr[index].right);
    for(int index = 1; index <= node_num; index++)
    {
        arr[arr[index].left].parent = index;
        arr[arr[index].right].parent = index;
    }
    for(int index = 1; index <= node_num; index++)
    {
        if(!arr[index].parent) {root = index; break;}
    }
    post_check(target_a, target_b, root);
    printf("%d", ans);
    return 0;
}
