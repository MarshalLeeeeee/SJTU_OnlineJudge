#include <stdio.h>
#include <string.h>
#include <iostream>
#define LEFT 0
#define RIGHT 1
using namespace std;

int order_num;
char order[30];
int a, b;
class SplayTree
{
private:
    struct Node
    {
        int data;
        int num;
        Node *left;
        Node *right;
        Node *parent;
        Node(void):left(NULL), right(NULL), parent(NULL), num(0){}
        Node (int value):left(NULL), right(NULL), parent(NULL), data(value), num(0){}
    };
    Node *root;

    Node *copy_node(Node *&node, Node *parent_node, Node *other_node)
    {
        if(other_node)
        {
            node = new Node;
            node->parent = parent_node;
            node->left = copy_node(node->left, node, other_node->left);
            node->right = copy_node(node->right, node, other_node->right);
            node->data = other_node->data;
            return node;
        }
        else return NULL;
    }

    void destroy_node(Node *&node)
    {
        if(node)
        {
            destroy_node(node->left);
            destroy_node(node->right);
            delete node;
            node = NULL;
        }
    }

    bool return_identity(Node *node)
    {
        if(node == node->parent->left) return LEFT;
        else return RIGHT;
    }

    void Zig(Node *node)// same as LL
    {
        Node *tmp1, *tmp2, *tmp3, *tmp4;
        tmp1 = node; tmp2 = node->left; tmp3 = node->right; tmp4 = node->left->left;
        tmp2->parent = tmp1->parent;
        if(tmp1->parent)
        {
            if(return_identity(tmp1) == LEFT) tmp2->parent->left = tmp2;
            else tmp2->parent->right = tmp2;
        }
        else root = tmp2;
        tmp1->left = tmp2->right;
        if(tmp2->right) tmp2->right->parent = tmp1;
        tmp2->right = tmp1;
        tmp1->parent = tmp2;
    }

    void Zag(Node *node)// same as RR
    {
        Node *tmp1, *tmp2, *tmp3, *tmp4;
        tmp1 = node; tmp2 = node->left; tmp3 = node->right; tmp4 = node->right->right;
        tmp3->parent = tmp1->parent;
        if(tmp1->parent)
        {
            if(return_identity(tmp1) == LEFT) tmp3->parent->left = tmp3;
            else tmp3->parent->right = tmp3;
        }
        else root = tmp3;
        tmp1->right = tmp3->left;
        if(tmp3->left) tmp3->left->parent = tmp1;
        tmp3->left = tmp1;
        tmp1->parent = tmp3;
    }

    void adjust(Node *node)
    {
        if(node->parent)
        {
            if(return_identity(node) == LEFT) Zig(node->parent);
            else Zag(node->parent);
            adjust(node);
        }
    }

    void adjust_to_root(Node *node)
    {
        if(node->parent != root)
        {
            if(return_identity(node) == LEFT) Zig(node->parent);
            else Zag(node->parent);
            adjust_to_root(node);
        }
    }

    Node *find_node(Node *node, int value)
    {
        if(node)
        {
            if(value == node->data) {adjust(node); return node;}
            else if(value < node->data) return find_node(node->left, value);
            else return find_node(node->right, value);
        }
        else return NULL;
    }

    Node *find_greater_node(int value)
    {
        bool flag = 0;
        Node *node = root;
        Node *ans;
        while(node)
        {
            if(!flag)
            {
                if(node->data > value) {ans = node; flag = 1; node = node->left;}
                else if(node->data == value) return node;
                else node = node->right;
            }
            else
            {
                if(node->data > value)
                {
                    ans = node;
                    node = node->left;
                }
                else if(node->data == value) return node;
                else node = node->right;
            }
        }
        if(!flag) return NULL;
        else return ans;
    }

    Node *find_less_node(int value)
    {
        bool flag = 0;
        Node *node = root;
        Node *ans;
        while(node)
        {
            if(!flag)
            {
                if(node->data < value) {ans = node; flag = 1; node = node->right;}
                else if(node->data == value) return node;
                else node = node->left;
            }
            else
            {
                if(node->data < value)
                {
                    ans = node;
                    node = node->right;
                }
                else if(node->data == value) return node;
                else node = node->left;
            }
        }
        if(!flag) return NULL;
        else return ans;
    }

    Node *find_insert_parent(Node *node, int value)
    {
        if(value >= node->data)
        {
            if(node->right) return find_insert_parent(node->right, value);
            else return node;
        }
        else
        {
            if(node->left) return find_insert_parent(node->left, value);
            else return node;
        }
    }

    Node *subtract(Node *node)
    {
        Node *ans;
        if(!node) return NULL;
        if(node->left)
        {
            ans = node->left;
            while(ans->right) ans = ans->right;
            return ans;
        }
        else
        {
            if(!node->parent) return NULL;
            if(return_identity(node) == RIGHT)
            {
                ans = node->parent;
                return ans;
            }
            ans = node->parent;
            while(ans != root && return_identity(ans) == LEFT)
                ans = ans->parent;
            if(ans == root) return NULL;
            else return ans->parent;
        }
    }

    Node *find_less(Node *node)
    {
        Node *ans = subtract(node);
        if(!ans) return NULL;
        else if(ans->data == node->data) return find_less(ans);
        else return ans;
    }

    Node *add(Node *node)
    {
        Node *ans;
        if(!node) return NULL;
        if(node->right)
        {
            ans = node->right;
            while(ans->left) ans = ans->left;
            return ans;
        }
        else
        {
            if(!node->parent) return NULL;
            if(return_identity(node) == LEFT)
            {
                ans = node->parent;
                return ans;
            }
            ans = node->parent;
            while(ans != root && return_identity(ans) == RIGHT)
                ans = ans->parent;
            if(ans == root) return NULL;
            else
                return ans->parent;
        }
    }

    Node *find_greater(Node *node)
    {
        Node *ans = add(node);
        if(!ans) return NULL;
        else if(ans->data == node->data) return find_greater(ans);
        else return ans;
    }

    int return_ii(Node *node, int value)
    {
        if(node)
        {
            if(value <= node_size(node->left)) return return_ii(node->left, value);
            else if(value == node_size(node->left) + 1) return node->data;
            else return return_ii(node->right, value - node_size(node->left) - 1);
        }
    }

public:
    //constructor and destructor
    SplayTree(void):root(NULL){}
    SplayTree(const SplayTree &other){copy_node(root, NULL, other.root);}
    ~SplayTree(void){destroy_node(root);}

    Node *find_node(int value)
    {
        return find_node(root, value);
    }

    void insert_node(int value)
    {
        if(!root)
        {
            root = new Node(value);
        }
        else
        {
            Node *father = find_insert_parent(root, value);
            Node *new_node = new Node(value);
            new_node->parent = father;
            if(value >= father->data) father->right = new_node;
            else father->left = new_node;
            adjust(new_node);
        }
    }

    bool delete_node(int value)
    {
        Node *target = find_node(root, value);
        if(target)
        {
            if(target->left && target->right)
            {
                Node *substitute = subtract(target);
                Node *new_node = new Node(substitute->data);
                new_node->parent = substitute->parent;
                if(substitute->parent)
                {
                    if(return_identity(substitute) == LEFT) substitute->parent->left = new_node;
                    else substitute->parent->right = new_node;
                }
                new_node->left = substitute->left;
                if(substitute->left) substitute->left->parent = new_node;
                new_node->right = substitute->right;
                if(substitute->right) substitute->right->parent = new_node;

                substitute->left = target->left;
                target->left->parent = substitute;
                substitute->right = target->right;
                target->right->parent = substitute;
                substitute->parent = target->parent;
                if(target->parent)
                {
                    if(return_identity(target) == LEFT) target->parent->left = substitute;
                    else target->parent->right = substitute;
                }
                else root = substitute;

                delete target;
                target = new_node;
            }
            if(!target->left && !target->right)
            {
                if(target->parent)
                {
                    if(return_identity(target) == LEFT) target->parent->left = NULL;
                    else target->parent->right = NULL;
                    adjust(target->parent);
                }
                else root = NULL;
                delete target;
            }
            else
            {
                if(target->left)
                {
                    target->left->parent = target->parent;
                    if(target->parent)
                    {
                        if(return_identity(target) == LEFT) target->parent->left = target->left;
                        else target->parent->right = target->left;
                        adjust(target->parent);
                    }
                    else root = target->left;
                    delete target;
                }
                else
                {
                    target->right->parent = target->parent;
                    if(target->parent)
                    {
                        if(return_identity(target) == LEFT) target->parent->left = target->right;
                        else target->parent->right = target->right;
                        adjust(target->parent);
                    }
                    else root = target->right;
                    delete target;
                }
            }
            return true;
        }
        else return false;
    }

    bool delete_less_than(int value)
    {
        Node *target = find_greater_node(value);
        if(target)
        {
            Node *p = find_less(target);
            Node *nr;
            if(!p) return false;
            else
            {
                nr = find_greater(p);
                adjust(nr);
                destroy_node(nr->left);
                nr->left = NULL;
                return true;
            }
        }
        else
        {
            destroy_node(root);
            root = NULL;
        }
    }

    bool delete_greater_than(int value)
    {
        Node *target = find_less_node(value);
        if(target)
        {
            Node *p = find_greater(target);
            Node *nr;
            if(!p) return false;
            else
            {
                nr = find_less(p);
                adjust(nr);
                destroy_node(nr->right);
                nr->right = NULL;
                return true;
            }
        }
        else
        {
            destroy_node(root);
            root = NULL;
        }
    }

    bool delete_interval(int a, int b)
    {
        if(a >= b) return false;
        Node *node_a, *node_b, *target_a, *target_b, *tmp_a, *tmp_b;
        target_a = find_less_node(a);
        target_b = find_greater_node(b);
        if(!target_a && !target_b){destroy_node(root); root = NULL;return 1;}
        else if(!target_a && target_b) {return delete_less_than(b);}
        else if(target_a && !target_b) {return delete_greater_than(a);}
        else ;
        tmp_a = find_greater(target_a);
        if(!tmp_a) return false;
        else node_a = subtract(tmp_a);
        tmp_b = find_less(target_b);
        if(!tmp_b) return false;
        else node_b = add(tmp_b);
        adjust(node_a);
        adjust_to_root(node_b);
        if(root->right->left)
        {
            destroy_node(root->right->left);
            root->right->left = NULL;
        }
        return true;
    }

    int node_size(Node *node)
    {
        if(!node) return 0;
        node->num = node_size(node->left) + node_size(node->right) + 1;
        return node->num;
    }

    int return_num(void){return node_size(root);}

    int return_i(int value)
    {
        return return_ii(root, value);
    }
};


int main()
{
    SplayTree t;
    bool flag;
    scanf("%d", &order_num);
    while(order_num--)
    {
        scanf("%s", order);
        if(!strcmp(order, "insert"))
        {
            scanf("%d", &a);
            t.insert_node(a);
        }
        else if(!strcmp(order, "delete"))
        {
            scanf("%d", &a);
            t.delete_node(a);
        }
        else if(!strcmp(order, "delete_less_than"))
        {
            scanf("%d", &a);
            t.delete_less_than(a);
        }
        else if(!strcmp(order, "delete_greater_than"))
        {
            scanf("%d", &a);
            t.delete_greater_than(a);
        }
        else if(!strcmp(order, "delete_interval"))
        {
            scanf("%d %d", &a, &b);
            t.delete_interval(a, b);
        }
        else if(!strcmp(order, "find"))
        {
            scanf("%d", &a);
            if(t.find_node(a)) printf("Y\n");
            else printf("N\n");
        }
        else if(!strcmp(order, "find_ith"))
        {
            scanf("%d", &a);
            if(a > t.return_num() || a <= 0) printf("N\n");
            else printf("%d\n", t.return_i(a));
        }
        else ;
    }
    return 0;
}
