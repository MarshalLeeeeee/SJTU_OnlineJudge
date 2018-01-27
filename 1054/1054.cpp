#include <stdio.h>
#include <iostream>
#define MAX 100001
using namespace std;
int root = 0;
int delta = 0;
int tail = 0;
int leave_num = 0;
int low_bound;
int num;
struct Node
{
    int left, right, parent;
    int value;
    int siz;
    Node(void):left(0), right(0), parent(0), siz(0){}
};
Node t[MAX];
void Update(int index)
{
    if(!index) return ;
    t[index].siz = t[t[index].left].siz + t[t[index].right].siz + 1;
}
void Zig(int index)
{
    int father = t[index].parent;
    int left_son = t[index].left;
    t[index].left = t[left_son].right;
    if(t[index].left) t[t[index].left].parent = index;
    t[left_son].right = index;
    t[index].parent = left_son;
    t[left_son].parent = father;
    if(!father) root = left_son;
    else
    {
        if(index == t[father].left) t[father].left = left_son;
        else t[father].right = left_son;
    }
    Update(index);
    Update(t[index].parent);
}
void Zag(int index)
{
    int father = t[index].parent;
    int right_son = t[index].right;
    t[index].right = t[right_son].left;
    if(t[index].right) t[t[index].right].parent = index;
    t[right_son].left = index;
    t[index].parent = right_son;
    t[right_son].parent = father;
    if(!father) root = right_son;
    else
    {
        if(index == t[father].left) t[father].left = right_son;
        else t[father].right = right_son;
    }
    Update(index);
    Update(t[index].parent);
}
void Splay(int index)
{
    while(t[index].parent)
    {
        if(t[t[index].parent].left == index) Zig(t[index].parent);
        else Zag(t[index].parent);
    }
}
void Insert(int value)
{
    if(!root)
    {
        tail++;
        t[tail].siz = 1;
        t[tail].value = value;
        t[tail].parent = t[tail].left = t[tail].right = 0;
        root = tail;
    }
    else
    {
        int curr = root, prev;
        while(curr)
        {
            prev = curr;
            t[curr].siz++;
            if(value <= t[curr].value) curr = t[curr].left;
            else curr = t[curr].right;
        }
        tail++;
        if(value <= t[prev].value) t[prev].left =tail;
        else t[prev].right = tail;
        t[tail].value=value;
        t[tail].siz=1;
        t[tail].parent=prev;
        Splay(tail);
    }
}
int Findith(int r, int i)
{
    if(i <= 0 || i > t[r].siz) return -1-delta;
    if(i == t[t[r].left].siz + 1) return t[r].value;
    else if(i < t[t[r].left].siz + 1) return Findith(t[r].left, i);
    else return Findith(t[r].right, i - (t[t[r].left].siz + 1));
}
void Del(int value)
{
    bool flag = 0;
    int curr = root, note, target = 0;
    while(curr)
    {
        if(!flag)
        {
            if(value <= t[curr].value)
            {
                flag = 1;
                target = curr;
                note = t[curr].value;
                curr = t[curr].left;
            }
            else curr = t[curr].right;
        }
        else
        {
            if(value > t[curr].value) curr = t[curr].right;
            else
            {
                target = curr;
                curr = t[curr].left;
            }
        }
    }
    if(!target) {leave_num += t[root].siz; root = 0;return ;}
    Splay(target);
    leave_num += t[t[target].left].siz;
    t[target].siz -= t[t[target].left].siz;
    if(t[target].left) t[t[target].left].parent = 0;
    t[target].left = 0;
}
int main(void)
{
    char op[3]; int k;
    scanf("%d %d", &num, &low_bound);
    while(num--)
    {
        scanf("%s %d", op, &k);
        switch(op[0])
        {
        case 'A': delta += k; break;
        case 'S': delta -= k; Del(low_bound - delta); break;
        case 'I': if(k >= low_bound) Insert(k - delta); break;
        case 'F': printf("%d\n", Findith(root, t[root].siz - k + 1)+delta);break;
        }
    }
    printf("%d\n", leave_num);
    return 0;
}

