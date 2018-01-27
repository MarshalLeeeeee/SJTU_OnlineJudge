#include <stdio.h>
using namespace std;
struct Node
{
    long long data;
    int seq[31];
};
Node point[31][31];
int num;

void link(Node &ans, Node &n1, int len1)
{
    for(int index = 1; index <= len1; index++)
        ans.seq[index] = n1.seq[index];
}
void link(Node &ans, Node &n1, int len1,  Node &n2, int len2)
{
    for(int index = 1; index <= len1 + len2; index++)
    {
        if(index <= len1) ans.seq[index] = n1.seq[index];
        else ans.seq[index] = n2.seq[index-len1];
    }
}
void link(Node &ans, Node &n1, int len1,  Node &n2, int len2, Node &n3, int len3)
{
    for(int index = 1; index <= len1 + len2 + len3; index++)
    {
        if(index <= len1) ans.seq[index] = n1.seq[index];
        else if(index <= len1 + len2) ans.seq[index] = n2.seq[index-len1];
        else ans.seq[index] = n3.seq[index-len1-len2];
    }
}
void print(Node &node, int len)
{
    for(int index = 1; index <= len; index++)
        printf("%d ", node.seq[index]);
}

int main()
{
    scanf("%d", &num);
    for(int index = 1; index <= num; index++)
    {
        scanf("%lld", &point[index][index].data);
        point[index][index].seq[1] = index;
    }
    Node tmp;
    Node maxinum;
    for(int index = 2; index <= num; index++)
    {
        for(int index2 = 1; index2 <= num + 1 - index; index2++)
        {
            int index3;
            for(index3 = index2, maxinum.data = 0; index3 < index2 + index; index3++)
            {
                if(index3 == index2)
                {
                    tmp.data = point[index2][index2].data + point[index2 + 1][index2 + index - 1].data;
                    link(tmp, point[index2][index2], 1, point[index2+1][index2+index-1], index - 1);
                }
                else if(index3 == index2 + index - 1)
                {
                    tmp.data = point[index2][index2 + index - 2].data + point[index2 + index - 1][index2 + index - 1].data;
                    link(tmp, point[index2][index2 + index - 2], index - 1, point[index2 + index - 1][index2 + index - 1], 1);
                }
                else
                {
                    tmp.data = point[index3][index3].data + point[index2][index3-1].data * point[index3+1][index2 + index - 1].data;
                    link(tmp, point[index3][index3], 1, point[index2][index3-1], index3 - index2, point[index3+1][index2 + index - 1], index2 + index - index3 - 1);
                }
                if(tmp.data > maxinum.data)
                {
                    maxinum.data = tmp.data;
                    link(maxinum, tmp, index);
                }
            }
            point[index2][index2+index-1].data = maxinum.data;
            link(point[index2][index2+index-1], maxinum, index);
        }
    }
    printf("%lld\n", point[1][num].data);
    print(point[1][num], num);
    return 0;
}
