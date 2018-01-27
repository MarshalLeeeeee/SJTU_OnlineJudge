#include <iostream>
#include <cmath>

using namespace std;

int if_is_prime(long);

int main()
{
    long num;
    cin >> num;
    if(if_is_prime(num)) cout << 0;
    else
    {
        long fd1 = num - 1;
        long fd2 = num + 1;
        while(!if_is_prime(fd1)) fd1--;
        while(!if_is_prime(fd2)) fd2++;
        cout << fd2 - fd1;
    }
    return 0;
}
int if_is_prime(long x)
{
    if(x == 2 || x == 3) return 1;
    int index;
    for(index = 2; index <= (int)sqrt(x); index++)
    {
        if(x % index == 0) return 0;
    }
    return 1;
}
