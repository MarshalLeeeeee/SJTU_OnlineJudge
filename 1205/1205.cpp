#include <iostream>

using namespace std;

int ack(int, int);

int main()
{
    int m, n;
    cin >> m >> n;
    cout << ack(m, n);
    return 0;
}
int ack(int m, int n)
{
    if(!m) return n + 1;
    else if(m && !n) return ack(m - 1, 1);
    else return ack(m - 1, ack(m, n - 1));
}
