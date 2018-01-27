#include <stdio.h>
using namespace std;

int N, M, count = 0;
int high[10001];
int low[10001];
int state[10001] = {0};
void quicksort(int ibegin, int iend)
{
    if(ibegin >= iend) return ;
    int pivot = low[ibegin], tmp;
    int left, right;
    for(left = ibegin; left <= iend; left++)
    {
        if(low[left] > pivot) break;
    }
    for(right = left+1; right <= iend; right++)
    {
        if(low[right] < pivot)
        {
            tmp = low[left];
            low[left] = low[right];
            low[right] = tmp;
            left++;
        }
    }
    low[ibegin] = low[left-1];
    low[left-1] = pivot;
    quicksort(ibegin, left-2);
    quicksort(left, iend);
}
void return_index(int value)
{
    int left = 0, right = M-1, mid;
    while(left <= right)
    {
        mid = (left+right) / 2;
        if(low[mid] < value) left = mid + 1;
        else if(low[mid] > value) right = mid - 1;
        else {right = mid; break;}
    }
    while(right >= 0 && (low[right] >= value || state[right]))
        right--;
    if(right < 0) return ;
    else
    {
        state[right] = 1;
        count++;
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for(int index = 0; index < N; index++) scanf("%d", &high[index]);
    for(int index = 0; index < M; index++) scanf("%d", &low[index]);
    quicksort(0, M-1);
    count += N;
    for(int index = 0; index < N; index++) return_index(high[index]);
    printf("%d", count);
    return 0;
}
