#include <iostream>
#include <cstring>

using namespace std;

void push(int *, int &, int);
void pop(int *, int &);

int main()
{
    int stack1[10000];
    int stack2[10000];
    int len1 = 0;
    int len2 = 0;
    char word[10000];
    int flag = 0;//flag = 1 represents error
    while(cin >> word)
    {
        if(!strcmp(word, "begin")) push(stack1, len1, 0);//push 0 to the stack1 if we read "begin"
        else if(!strcmp(word, "if"))
        {
            if(!len2) push(stack2, len2, 1);
            else if(stack2[len2 - 1] == 1)
            {
                flag = 1;
                break;
            }
            else push(stack2, len2, 1);//push 1 to the stack if we read "if" and no "if" right forward
        }
        else if(!strcmp(word, "then"))
        {
            if(!len2 || stack2[len2 - 1] != 1)
            {
                flag = 1;
                break;
            }
            else push(stack2, len2, 2);
        }
        else if(!strcmp(word, "else"))
        {
            if(!len2 || stack2[len2 - 1] != 2)
            {
                flag = 1;
                break;
            }
            else
            {
                pop(stack2, len2);
                pop(stack2, len2);
            }
        }
        else if(!strcmp(word, "end"))
        {
            if(!len1 || stack1[len1 - 1] != 0)
            {
                flag = 1;
                break;
            }
            else pop(stack1, len1);
        }
    }
    if(len1) flag = 1;
    if(flag) cout << "Error!";
    else cout << "Match!";
    return 0;
}
void push(int *stack1, int &len, int value)
{
    stack1[len++] = value;
}
void pop(int *stack1, int &len)
{
    len--;
}
