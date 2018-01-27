#include <iostream>

using namespace std;

void person_number_input(long &);
void wait_time_input(int *&, const long);
long max_of_three_int(const long, const long, const long);
long min_of_three_int(const long, const long, const long);
void print_time_in_old_way(const int *, const int);
void print_time_in_new_way(const int *, const int);
void add_client(long &, int &, const int *, const int);

int main()
{
    long person_number;
    int *process_time;
    person_number_input(person_number);
    wait_time_input(process_time, person_number);
    print_time_in_old_way(process_time, person_number); cout << endl;
    print_time_in_new_way(process_time, person_number);
    return 0;
}
void person_number_input(long &x)
{
    cin >> x;
}
void wait_time_input(int *&ptr, const long x)
{
    int index;
    ptr = new int[x];
    for(index = 0; index < x; index++)
    {
        cin >> ptr[index];
    }
}
long max_of_three_int(const long a, const long b, const long c)
{
    if(a > b)
    {
        if(c > a) return c;
        else return a;
    }
    else
    {
        if(c > b) return c;
        else return b;
    }
}
long min_of_three_int(const long a, const long b, const long c)
{
    if(a < b)
    {
        if(c < a) return c;
        else return a;
    }
    else
    {
        if(c < b) return c;
        else return b;
    }
}
void print_time_in_old_way(const int *process_time, const int person_number)
{
    int index;
    long wait;
    long sum1 = 0, sum2 = 0, sum3 = 0;
    long sum4 = 0, sum5 = 0, sum6 = 0;
    for(index = 0; index < person_number; index++)
    {
        if(index % 3 == 1){sum1 += process_time[index]; sum4 += sum1;}
        else if(index % 3 == 2){sum2 += process_time[index]; sum5 += sum2;}
        else{sum3 += process_time[index]; sum6 += sum3;}
        if(person_number - index - 1 == 3) wait = sum4 + sum5 + sum6;
    }
    if(person_number < 4) cout << 0 << " ";
    else cout << wait << " ";
    cout << max_of_three_int(sum1, sum2, sum3);
}
void print_time_in_new_way(const int *process_time, const int person_number)
{
    long account1 = 0, account2 = 0, account3 = 0;
    long min;
    long sum = 0, wait = 0;
    int index;
    for(index = 0; index < person_number; )
    {
        min = min_of_three_int(account1, account2, account3);
        account1 -= min; account2 -= min; account3 -= min;
        sum += min;
        wait += (person_number - index) * min;
        add_client(account1, index, process_time, person_number);
        add_client(account2, index, process_time, person_number);
        add_client(account3, index, process_time, person_number);
        if(index == person_number)
        {
            cout << wait << " ";
            cout << max_of_three_int(account1, account2, account3) + sum;
        }
    }
}
void add_client(long &account, int &index, const int *process_time, const int person_number)
{
    if(!account)
    {
        if(index < person_number)
        {
            account += process_time[index++];
        }
        else
        {
            return ;
        }
    }
}
