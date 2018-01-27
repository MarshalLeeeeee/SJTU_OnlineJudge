#include <stdio.h>
using namespace std;
int num;
int data[10000];
void quicksort(int ibegin, int iend)
{
    if(ibegin >= iend) return;
    int pivot = data[ibegin];
    int tmp, left, right;
    for(left = ibegin; left <= iend; left++)
    {
        if(pivot < data[left]) break;
    }
    for(right = left + 1; right <= iend; right++)
    {
        if(pivot > data[right])
        {
            tmp = data[right];
            data[right] = data[left];
            data[left] = tmp;
            left++;
        }
    }
    data[ibegin] = data[left - 1];
    data[left - 1] = pivot;
    quicksort(ibegin, left - 2);
    quicksort(left, iend);
}
int main()
{
    int index;
    int d;
    scanf("%d", &num);
    for(index = 0; index < num; index++)
    {
        scanf("%d", &d);
        data[index] = d;
    }
    quicksort(0, num-1);
    for(index = 0; index < num; index++)
    {
        printf("%d ", data[index]);
    }
    return 0;
}
