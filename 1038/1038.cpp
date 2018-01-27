#include <iostream>

using namespace std;

int josephus_problem(const long *, int);

int main()
{
    int n;
    cin >> n;
    long *step;
    step = new long[n - 1];
    int index;
    for(index = 0; index < n - 1; index++)
    {
        cin >> step[index];
    }
    cout << josephus_problem(step, n) + 1 << endl;
    return 0;
}
int josephus_problem(const long *step, int person)
{
    if(person == 1) return 0;
    else return (josephus_problem(step + 1, person - 1) + (*step)) % person;
}
