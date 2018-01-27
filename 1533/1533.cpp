#include <iostream>

using namespace std;

int n, x, y;
int ans(int n, int x, int y)
{
    if(x == 1) return y - 1;
    if(y == n) return n - 2 + x;
    return 2*n-1+ans(n-1, n+1-x, n-y);
}
int main()
{
    cin >> n >> x >> y;
    cout << ans(n, x, y);
    return 0;
}
