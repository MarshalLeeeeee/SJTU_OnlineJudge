#include <iostream>

using namespace std;

void game_number_input(int &);
void range_list_input(long long *&, const int);
void print_result(const long long *, const int);

int main()
{
    int game_number;
    long long *range_list;
    game_number_input(game_number);
    range_list_input(range_list, game_number);
    print_result(range_list, game_number);
    return 0;
}
void game_number_input(int &x)
{
    cin >> x;
}
void range_list_input(long long *&ptr, const int n)
{
    ptr = new long long[n];
    int index;
    for(index = 0; index < n; index++)
    {
        cin >> ptr[index];
    }
}
void print_result(const long long *ptr, const int n)
{
    int index;
    for(index = 0; index < n; index++)
    {
        if(ptr[index]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
