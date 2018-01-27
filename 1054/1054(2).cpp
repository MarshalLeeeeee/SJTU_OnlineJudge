#include <iostream>
#include <stdio.h>
using namespace std;

struct TreeNode
{
    int Left;
    int Right;
    int parent;
    int Size;
    int val;
};

TreeNode t[100005];
int root=0;
int total=0;
int tmpmin;
int cnt=0;
int change=0;

void putSize(int x)
{
    t[x].Size=t[t[x].Left].Size+t[t[x].Right].Size+1;
}

void LL(int &x)
{
    int father=t[x].parent;
    int gfather=t[father].parent;
    if(father==t[gfather].Left)t[gfather].Left=x;
    else t[gfather].Right=x;
    t[x].parent=gfather;
    t[father].Left=t[x].Right;
    t[t[x].Right].parent=father;
    t[x].Right=father;
    t[father].parent=x;
    putSize(father);
    putSize(x);
    if(father==root)root=x;
}

void RR(int &x)
{
    int father=t[x].parent;
    int gfather=t[father].parent;
    if(father==t[gfather].Left)t[gfather].Left=x;
    else t[gfather].Right=x;
    t[x].parent=gfather;
    t[father].Right=t[x].Left;
    t[t[x].Left].parent=father;
    t[father].parent=x;
    t[x].Left=father;
    putSize(father);
    putSize(x);
    if(father==root)root=x;
}

void splay(int &x)
{
    while(t[x].parent!=0){
        if(t[t[x].parent].Left==x)LL(x);
        else RR(x);
    }
}

void ins(int k)
{
    if(root==0){
        total++;
        root=total;
        t[total].val=k;
        t[total].Size=1;
        return ;
    }
    total++;
    int r=root;
    int tmp;
    while(r!=0){
        tmp=r;
        t[r].Size++;
        if(k<t[r].val)r=t[r].Left;
        else r=t[r].Right;
    }
    if(t[tmp].val>k)t[tmp].Left=total;
    else t[tmp].Right=total;
    t[total].val=k;
    t[total].Size=1;
    t[total].parent=tmp;
    splay(total);
}

int findith(int x,int i)
{
    if(i>t[root].Size)return -1;
    if(i-1==t[t[x].Right].Size)return t[x].val;
    else if(i-1<t[t[x].Right].Size)return findith(t[x].Right,i);
    else return findith(t[x].Left,i-1-t[t[x].Right].Size);
}

int delless(int &x,int f)
{
    if(x==0)return 0;
    int c=0;
    if(t[x].val<tmpmin){
        c=delless(t[x].Right,x)+t[t[x].Left].Size+1;
        t[t[x].Right].Size=t[x].Size-c;
        x=t[x].Right;
        t[x].parent=f;
    }
    else{
        c=delless(t[x].Left,x);
        t[x].Size-=c;
    }
    return c;
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    char op[3];int k;
    tmpmin=m;
    for(int idxx=0;idxx<n;++idxx){
        scanf("%s",op);
        scanf("%d",&k);
        if(op[0]=='I'){
            if(k<m)continue;
            ins(k+change);
            continue;
        }
        if(op[0]=='A'){
            tmpmin-=k;
            change-=k;
            continue;
        }
        if(op[0]=='S'){
            tmpmin+=k;
            change+=k;
            int tmp=delless(root,0);
            cnt+=tmp;
            continue;
        }
        if(op[0]=='F'){
            int res=findith(root,k);
            if(res==-1)printf("%d\n",-1);
            else printf("%d\n",res+m-tmpmin);
        }
    }
    printf("%d\n",cnt);
    return 0;
}
