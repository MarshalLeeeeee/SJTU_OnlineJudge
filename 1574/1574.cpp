#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long quick_pow(long x, long long k)
{
    if(k == 0) return 1;
    else if(k == 1) return x;
    else
    {
        long tmp;
        if(k % 2 == 0)
        {
            tmp = quick_pow(x, k / 2);
            return tmp * tmp;
        }
        else
        {
            tmp = quick_pow(x, k / 2);
            return tmp * tmp * x;
        }
    }
}
long quick_pow_mod(long long exp, long mult, long n)
{
    if(exp == 0) return 1;
    else if(exp == 1) return mult;
    else
    {
        long tmp;
        if(exp % 2 == 0)
        {
            tmp = quick_pow_mod(exp / 2, mult, n) % n;
            return (long long)tmp * tmp % n;
        }
        else
        {
            tmp = quick_pow_mod(exp / 2, mult, n) % n;
            return (long long)tmp * tmp * mult % n;
        }
    }
}
long get_ans(long n, long long k)
{
    long long exp = (long long)log10(n) + 1;
    long mult = quick_pow(10, exp) % n;
    if(mult == 0) return 0;
    else if(mult == 1) return quick_pow(10, k % exp) % n;
    else return (long long)quick_pow_mod(k / exp, mult, n) * quick_pow(10, k % exp) % n;
}
int main()
{
    long n, m, x;
    long long k;
    cin >> n >> m >> k >> x;
    cout << ((get_ans(n, k) * (long long)m) + x) % n;
    //printf("%lld", ((get_ans(n, k) * (long long)m) + x) % n);
    return 0;
}
