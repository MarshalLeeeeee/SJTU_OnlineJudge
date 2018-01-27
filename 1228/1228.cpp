#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct Node
{
    long long even, odd;
    Node(void): even(0), odd(0){}
} value;
int num;
bool data[401][401];
bool save[401];
value record[401];
long long even_ans = 0;
long long odd_ans = 0;
void process(int n)
{
    int index, index2;
    for(index = 1; index <= num; index++)
    {
        save[index] = 0;
        for(index2 = 1; index2 <= n; index2++)
        {
            save[index] ^= data[index2][index];
        }
    }
    for(index = 1; index <= num+1-n; index++)
    {
        if(index != 1)
        {
            for(index2 = 1; index2 <= num; index2++)
            {
                save[index2] ^= data[index-1][index2];
                save[index2] ^= data[index+n-1][index2];
            }
        }
        for(index2 = 1; index2 <= num; index2++)
        {
            if(index2 == 1)
            {
                if(save[index2]) {record[index2].odd = 1; record[index2].even = 0;}
                else {record[index2].odd = 0; record[index2].even = 1;}
            }
            else if(index2 == 2)
            {
                if(save[index2])
                {
                    if(record[index2-1].odd) {record[index2].odd = 2; record[index2].even = 1;}
                    else {record[index2].odd = 2; record[index2].even = 1;}
                }
                else
                {
                    if(record[index2-1].odd) {record[index2].odd = 2; record[index2].even = 1;}
                    else {record[index2].even = 3; record[index2].odd = 0;}
                }
            }
            else
            {
                if(save[index2])
                {
                    record[index2].odd = record[index2-1].odd + record[index2-1].even - record[index2-2].even + 1;
                    record[index2].even = record[index2-1].even + record[index2-1].odd - record[index2-2].odd;
                }
                else
                {
                    record[index2].odd = record[index2-1].odd + record[index2-1].odd - record[index2-2].odd;
                    record[index2].even = record[index2-1].even + record[index2-1].even - record[index2-2].even + 1;
                }
            }
        }
        odd_ans += record[num].odd;
        even_ans += record[num].even;
    }
}

int main()
{
    int index1, index2, index3, tmp;
    scanf("%d", &num);
    for(index1 = 1; index1 <= num; index1++)
    {
        for(index2 = 1; index2 <= num; index2++)
        {
            scanf("%d", &tmp);
            data[index1][index2] = tmp % 2;
        }
    }
    for(index1 = 1; index1 <= num; index1++)
    {
        process(index1);
    }
    printf("%lld %lld", odd_ans, even_ans);
    return 0;
}
