#include <stdio.h>
using namespace std;

long long num;
long long arr[10000001];
long long record[10000001];
long long save[10000001];
long long save_len;

long long binary(long long value)
{
    long long left = 1, right = save_len;
    long long mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(save[mid] > value)
        {
            right = mid - 1;
        }
        else if(save[mid] < value)
        {
            left = mid + 1;
        }
        else return mid;
    }
    return left;
}

int main()
{
    scanf("%lld", &num);
    long long index, index2;
    long long max;
    for(index = 1; index <= num; index++)
    {
        scanf("%lld", &arr[index]);
    }
    for(index = 1; index <= num; index++)
    {
        if(index == 1)
        {
            record[index] = 1;
            save[index] = arr[index];
            save_len = 1;
        }
        else
        {
            record[index] = binary(arr[index]);

            if(record[index] > save_len)
            {
                save[record[index]] = arr[index];
                save_len++;
            }
            if(arr[index] < save[record[index]]) save[record[index]] = arr[index];
        }
    }
    for(index = 1, max = 0; index <= num; index++)
    {
        if(record[index] > max) max = record[index];
    }
    printf("%lld", max);
    return 0;
}
