#include <iostream>
#define MOD 2010
#define N_MOD 2040
using namespace std;
int a, b, c;
long long n;
struct matrix
{
    int m[2][2];
    matrix(void){m[0][0] = 1; m[1][0] = 1; m[0][1] = 1; m[1][1] = 0;}
    matrix(int a, int b, int c, int d){m[0][0] = a; m[1][0] = c; m[0][1] = b; m[1][1] = d;}
    matrix &operator=(const matrix &other){m[0][0] = other.m[0][0]; m[1][0] = other.m[1][0]; m[0][1] = other.m[0][1]; m[1][1] = other.m[1][1];}
    const matrix operator*(const matrix &other)
    {
        matrix ans;
        ans.m[0][0] = m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0]; ans.m[0][0] %= MOD;
        ans.m[0][1] = m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1]; ans.m[0][1] %= MOD;
        ans.m[1][0] = m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0]; ans.m[1][0] %= MOD;
        ans.m[1][1] = m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1]; ans.m[1][1] %= MOD;
        return ans;
    }
};
matrix matrix_pow(const matrix &m, int p)
{
    if(p == 0) {matrix ans(1, 0, 0, 1); return ans;}
    else if(p == 1) return m;
    else
    {
        matrix ans = matrix_pow(m, p/2);
        ans = ans * ans;
        if(p % 2 == 0) return ans;
        else return (ans * m);
    }
}


int main()
{
    matrix ma, ans;
    cin >> n; n %= N_MOD;
    ans = matrix_pow(ma, n-1);
    cout << ans.m[0][0];
    return 0;
}
