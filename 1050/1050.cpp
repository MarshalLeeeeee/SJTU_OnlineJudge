#include <stdio.h>
using namespace std;
long long order_num;
long long group_num;
struct Node
{
    long long data;
    Node *left;
    Node *right;
    Node(void):left(NULL), right(NULL){}
};
class SkewHeap
{
public:
    Node *root;

    void delete_node(Node *&node)
    {
        if(node)
        {
            if(node->left) delete_node(node->left);
            if(node->right) delete_node(node->right);
            delete node;
            node = NULL;
        }
    }
    void copy_node(Node *node, Node *other_node)
    {
        if(other_node->left)
        {
            node->left = new Node;
            copy_node(node->left, other_node->left);
        }
        else node->left = NULL;
        if(other_node->right)
        {
            node->right = new Node;
            copy_node(node->right, other_node->right);
        }
        else node->right = NULL;
        node->data = other_node->data;
    }

    SkewHeap(void):root(NULL){}
    ~SkewHeap(void){delete_node(root);}

    void push(long long value)
    {
        if(root == NULL)
        {
            root = new Node;
            root->data = value;
            return ;
        }
        Node *new_node = new Node;
        new_node->data = value;
        root = merge_node(root, new_node);
    }
    Node *merge_node(Node *&node, Node *&other_node)
    {
        if(node == NULL){node = other_node;return node;}
        if(other_node == NULL) return node;
        if(node->data < other_node->data) {node->right = merge_node(node->right, other_node); Node *tmp; tmp = node->right; node->right = node->left; node->left = tmp; return node;}
        else {other_node->right = merge_node(node, other_node->right); Node *tmp; tmp = node->right; node->right = node->left; node->left = tmp; return other_node;}
    }
    long long pop(void)
    {
        if(root == NULL) return -1;
        if(root->left == NULL && root->right == NULL) {long long v = root->data; delete_node(root); return v;}
        else {long long v = root->data; root = merge_node(root->left, root->right); return v;}
    }
};
SkewHeap heap[300000];
int main()
{
    long long index;
    long long choice;
    long long d, a, b;
    scanf("%lld", &group_num);
    scanf("%lld", &order_num);
    for(index = 0; index < group_num; index++)
    {
        scanf("%lld", &d);
        heap[index].push(d);
    }
    for(index = 0; index < order_num; index++)
    {
        scanf("%lld", &choice);
        switch(choice)
        {
        case 0:
            {
                scanf("%lld", &a);
                scanf("%lld", &b);
                heap[a].root = heap[a].merge_node(heap[a].root, heap[b].root);
                heap[b].root = NULL;
                break;
            }
        case 1:
            {
                scanf("%lld", &a);
                printf("%lld\n", heap[a].pop());
                break;
            }
        case 2:
            {
                scanf("%lld", &a);
                scanf("%lld", &b);
                heap[a].push(b);
                break;
            }
        }
    }
    return 0;
}
