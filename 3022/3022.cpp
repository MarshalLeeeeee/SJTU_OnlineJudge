#include <iostream>
#include <stdio.h>
#define LEN 20000
using namespace std;

int d1[LEN] = {0};
int d1_len = 0;
int d2[LEN] = {0};
int d2_len = 0;
int d3[LEN] = {0};
int d3_len = 0;
int d4[LEN] = {0};
int d4_len = 0;
int day;
void add(int *, int *, int *, int *, int &, int &, int &, int &);
void print(int *, int);

int main()
{
    cin >> day;
    d1[0] = 1; d1_len = 1;
    d2[0] = 2; d2_len = 1;
    d3[0] = 4; d3_len = 1;
    int index;
    for(index = 4; index <= day; index++)
    {
        if(index % 4 == 0) add(d4, d1, d2, d3, d4_len, d1_len, d2_len, d3_len);
        else if(index % 4 == 1) add(d1, d2, d3, d4, d1_len, d2_len, d3_len, d4_len);
        else if(index % 4 == 2) add(d2, d3, d4, d1, d2_len, d3_len, d4_len, d1_len);
        else add(d3, d4, d1, d2, d3_len ,d4_len, d1_len, d2_len);
    }
    if(day == 1) cout << 2;
    else if(day == 2) cout << 4;
    else if(day == 3) cout << 7;
    else
    {
        if(day % 4 == 0) {add(d1, d2, d3, d4, d1_len, d2_len, d3_len, d4_len); print(d1, d1_len);}
        else if(day % 4 == 1) {add(d2, d3, d4, d1, d2_len, d3_len, d4_len, d1_len); print(d2, d2_len);}
        else if(day % 4 == 2) {add(d3, d4, d1, d2, d3_len, d4_len, d1_len, d2_len); print(d3, d3_len);}
        else {add(d4, d1, d2, d3, d4_len, d1_len, d2_len, d3_len); print(d4, d4_len);}
    }
    return 0;
}
void add(int *d1, int *d2, int *d3, int *d4, int &d1_len, int &d2_len, int &d3_len, int &d4_len)
{
    int i;
    int digit;
    int x = 0;
    for(i = 0; i < LEN; i++)
    {
        digit = d2[i] + d3[i] + d4[i] + x;
        if(digit == 0 && (i >= d2_len && i >= d3_len && i >= d4_len)) break;
        x = digit / 10;
        digit %= 10;
        d1[i] = digit;
    }
    d1_len = i;
}
void print(int *d1, int d1_len)
{
    int index;
    for(index = d1_len-1; index >= 0; index--)
    {
        cout << d1[index];
    }
}
