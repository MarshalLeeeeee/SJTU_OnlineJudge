#include <iostream>
#include <cstring>
#define ROW 100
#define LEN 2001
#define ADD 100
#define ORDER 5

using namespace std;

void string_input(char *, int);
void print_list(char (*)[LEN], int, int, int);
void ins(char (*)[LEN], int, int, int, const char *);
void del(char (*)[LEN], int, int, int, int);

int main()
{
    char string_list[ROW][LEN];
    char order[ORDER];
    int index = 0;
    int row;
    int start_row, end_row;
    int ins_row, ins_col;
    int del_row, del_col, del_n;
    char add_string[ADD];
    cin.getline(string_list[index], LEN);
    while(strcmp(string_list[index], "******"))
    {
        index++;
        cin.getline(string_list[index], LEN);
    }
    row = index++;//exact row
    string_input(order, ORDER);
    while(strcmp(order, "quit"))
    {
        if(!strcmp(order, "list"))
        {
            cin >> start_row >> end_row;cin.get();
            print_list(string_list, row, start_row, end_row);
        }
        else if(!strcmp(order, "ins"))
        {
            cin >> ins_row >> ins_col;cin.get();
            cin.getline(add_string, ADD);
            ins(string_list, row, ins_row, ins_col, add_string);
        }
        else if(!strcmp(order, "del"))
        {
            cin >> del_row >> del_col >> del_n;cin.get();
            del(string_list, row, del_row, del_col, del_n);
        }
        else
        {
            cin.sync();
            cout << "Error!" << endl;
        }
        string_input(order, ORDER);
    }
    print_list(string_list, row, 1, row);
    return 0;
}
void print_list(char (*string_list)[LEN], int row, int start_row, int end_row)
{
    if(1 <= start_row && start_row <= end_row && end_row <= row)
    {
        int index;
        for(index = start_row - 1; index < end_row; index++)
        {
            cout << string_list[index] << endl;
        }
    }
    else
    {
        cout << "Error!" << endl;
    }
}
void ins(char (*string_list)[LEN], int row, int ins_row, int ins_col, const char* add_str)
{
    if((1 <= ins_row && ins_row <= row) && (1 <= ins_col && ins_col <= strlen(string_list[ins_row - 1]) + 1))
    {
        char tmp1[LEN];
        strcpy(tmp1, string_list[ins_row - 1]);
        string_list[ins_row - 1][ins_col - 1] = 0;
        strcat(string_list[ins_row - 1], add_str);
        strcat(string_list[ins_row - 1], tmp1 + ins_col - 1);
    }
    else
    {
        cout << "Error!" << endl;
    }
}
void del(char (*string_list)[LEN], int row, int del_row, int del_col, int n)
{
    if((1 <= del_row && del_row <= row) && (1 <= del_col && del_col + n <= strlen(string_list[del_row - 1]) + 1) && (0 <= n) && (del_col != 1 || n != strlen(string_list[del_row - 1])))
    {
        char tmp1[LEN];
        strcpy(tmp1, string_list[del_row - 1]);
        string_list[del_row - 1][del_col - 1] = 0;
        strcat(string_list[del_row - 1], tmp1 + del_col + n - 1);
    }
    else
    {
        cout << "Error!" << endl;
    }
}
void string_input(char *str, int len)
{
    char tmp;
    int index;
    for(index = 0; index < len; index++)
    {
        tmp = cin.get();
        if(tmp != ' ' && tmp != '\n')
        {
            str[index] = tmp;
        }
        else
        {
            break;
        }
    }
    str[index] = 0;
}
