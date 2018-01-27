#include <iostream>
#include <cstdio>
using namespace std;
struct bigInt
{
    int data[3000];
    int tail;
public:
    bigInt(void)
    {
        for(int index = 0; index < 3000; index++)
            data[index] = 0;
        tail = 0;
    }
    bigInt(int value)
    {
        for(int index = 0; index < 3000; index++)
            data[index] = 0;
        tail = 0;
        int digit;
        while(value)
        {
            data[tail++] = value % 10;
            value /= 10;
        }
    }
    const bigInt operator+(const bigInt &other)
    {
        bigInt ans;
        int addition = 0;
        int max_tail = tail > other.tail ? tail : other.tail;
        for(int index = 0; index < max_tail; index++)
        {
            ans.data[index] = data[index] + other.data[index] + addition;
            addition = ans.data[index] / 10;
            ans.data[index] %= 10;
            ans.tail++;
        }
        if(addition)
            ans.data[ans.tail++] = 1;
        return ans;
    }
    bigInt &operator=(const bigInt &other)
    {
        for(int index = 0; index < other.tail; index++)
        {
            data[index] = other.data[index];
        }
        tail = other.tail;
        return *this;
    }
    bigInt &operator=(int value)
    {
        for(int index = 0; index < 3000; index++)
            data[index] = 0;
        tail = 0;
        int digit;
        while(value)
        {
            data[tail++] = value % 10;
            value /= 10;
        }
        return *this;
    }
};
bigInt data[4][2];
bigInt a, b, c, d, e, f;
int n;
void calc(int value)
{
    for(int index = 4; index <= value; index++)
    {
        e = d + b;
        f = d + c;
        a = c;
        b = d;
        c = e;
        d = f;
    }
}
void show(bigInt &x)
{
    for(int index = x.tail-1; index >= 0; index--)
    {
        printf("%d", x.data[index]);
    }
}
int main()
{
    data[1][0] = 1;
    data[1][1] = 1;
    data[2][0] = 2;
    data[2][1] = 2;
    data[3][0] = 3;
    data[3][1] = 4;
    scanf("%d", &n);
    if(n == 1) printf("2");
    else if(n == 2) printf("4");
    else if(n == 3) printf("8");
    else
    {
        a = data[2][0];
        b = data[2][1];
        c = data[3][0];
        d = data[3][1];
        calc(n);
        bigInt ans = c + d;
        show(ans);
    }
    return 0;
}
