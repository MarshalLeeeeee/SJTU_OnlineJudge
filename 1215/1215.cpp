#include <stdio.h>
#include <cstring>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(void):left(NULL), right(NULL){}
};
class Btree
{
public:
    Node *root;//brother tree

    void copy_node(Node *node, const Node *other)
    {
        if(other->left)
        {
            node->left = new Node;
            copy_node(node->left, other->left);
        }
        else node->left = NULL;
        if(other -> right)
        {
            node -> right = new Node;
            copy_node(node->right, other->right);
        }
        else node->right = NULL;
        node->data = other->data;
    }
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

    Btree(void):root(NULL){}
    Btree(Node *node)
    {
        if(node)
        {
            root = new Node;
            copy_node(root, node);
            if(root->right) delete_node(root->right);
        }
        else root = NULL;
    }
    Btree(int value)
    {
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    ~Btree(void){delete_node(root);}

    Btree &operator=(const Btree &other)
    {
        if(this == &other) return *this;
        delete_node(root);
        if(other.root)
        {
            root = new Node;
            copy_node(root, other.root);
        }
        else root = NULL;
        return *this;
    }
    const Btree operator+(Btree &other)
    {
        if(root->data > other.root->data)
        {
            Btree ans(other.root);
            Node *tmp;
            if(ans.root->left)
            {
                tmp = ans.root->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = new Node;
                ans.copy_node(tmp->right, root);
            }
            else
            {
                ans.root->left = new Node;
                ans.copy_node(ans.root->left, root);
            }
            return ans;
        }
        else
        {
            Btree ans(root);
            Node *tmp;
            if(ans.root->left)
            {
                tmp = ans.root->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = new Node;
                ans.copy_node(tmp->right, other.root);
            }
            else
            {
                ans.root->left = new Node;
                ans.copy_node(ans.root->left, other.root);
            }
            return ans;
        }
    }
    void operator+=(Btree &other)
    {
        if(root->data > other.root->data)
        {
            Btree ans(other.root);
            Node *tmp;
            if(ans.root->left)
            {
                tmp = ans.root->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = new Node;
                ans.copy_node(tmp->right, root);
            }
            else
            {
                ans.root->left = new Node;
                ans.copy_node(ans.root->left, root);
            }
            delete_node(root);
            root = new Node;
            copy_node(root, ans.root);
        }
        else
        {
            Btree ans(root);
            Node *tmp;
            if(ans.root->left)
            {
                tmp = ans.root->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = new Node;
                ans.copy_node(tmp->right, other.root);
            }
            else
            {
                ans.root->left = new Node;
                ans.copy_node(ans.root->left, other.root);
            }
            delete_node(root);
            root = new Node;
            copy_node(root, ans.root);
        }
    }
};
Btree btree_list[20];
int order_num;
void add_tree(Btree &t, int start)
{
    int index;
    for(index = start; index < 20; index++)
    {
        if(btree_list[index].root)
        {
            t += btree_list[index];
            btree_list[index].delete_node(btree_list[index].root);
        }
        else
        {
            btree_list[index] = t;
            return ;
        }
    }
}
void delete_min(void)
{
    int mininum = 32000;
    int minindex = -1;
    int index;
    for(index = 0; index < 20; index++)
    {
        if(btree_list[index].root)
        {
            if(btree_list[index].root->data < mininum)
            {
                mininum = btree_list[index].root->data;
                minindex = index;
            }
        }
        else continue;
    }
    if(minindex == -1) return ;
    if(minindex == 0)
    {
        btree_list[0].delete_node(btree_list[0].root);
        return ;
    }
    Btree tmp(btree_list[minindex].root);
    btree_list[minindex].delete_node(btree_list[minindex].root);
    Node *tmp_node;
    for(index = 0; index < minindex; index++)
    {
        if(index == 0) tmp_node = tmp.root->left;
        else tmp_node = tmp_node->right;
        Btree a_tree(tmp_node);
        add_tree(a_tree, index);
    }
}
int return_min(void)
{
    int mininum = 32000;
    int index;
    for(index = 0; index < 20; index++)
    {
        if(btree_list[index].root)
        {
            if(btree_list[index].root->data < mininum)
            {
                mininum = btree_list[index].root->data;
            }
        }
        else continue;
    }
    return mininum;
}
int main()
{
    int index, index2;
    for(index = 0; index < 20; index++)
    {
        btree_list[index].root = NULL;
    }
    scanf("%d", &order_num);
    int value;
    char order[10];
    for(index = 0; index < order_num; index++)
    {
        scanf("%s", order);
        if(!strcmp(order, "insert"))
        {
            scanf("%d", &value);
            Btree a_tree(value);
            add_tree(a_tree, 0);
        }
        if(!strcmp(order, "delete"))
        {
            delete_min();
        }
        if(!strcmp(order, "min"))
        {
            printf("%d\n", return_min());
        }
    }
    return 0;
}
