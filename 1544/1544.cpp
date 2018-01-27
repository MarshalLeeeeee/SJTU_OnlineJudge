#include <stdio.h>
#define M 1000000007
using namespace std;
struct Node
{
    long long time[11];
    Node(void)
    {
        int index;
        for(index = 0; index <= 10; index++) time[index] = 0;
    }
};
long long origin_data[100001];
long long sort_data[100001];
long long index_data[100001];
long long index_data_tail = 0;
Node bit[100001];
long long n;//number of Node
int k;//k element
long long ans_time[11];

void quicksort(long long ibegin, long long iend)
{
    if(ibegin >= iend) return ;
    long long pivot = sort_data[ibegin];
    long long left, right, tmp;
    for(left = ibegin; left <= iend; left++)
    {
        if(sort_data[left] > pivot) break;
    }
    for(right = left + 1; right <= iend; right++)
    {
        if(sort_data[right] < pivot)
        {
            tmp = sort_data[left];
            sort_data[left] = sort_data[right];
            sort_data[right] = tmp;
            left++;
        }
    }
    sort_data[ibegin] = sort_data[left - 1];
    sort_data[left - 1] = pivot;
    quicksort(ibegin, left - 2);
    quicksort(left, iend);
}
long long binary_index(long long value)
{
    long long left = 1, right = index_data_tail, mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(index_data[mid] < value) left = mid + 1;
        else if(index_data[mid] > value) right = mid - 1;
        else return mid;
    }
}
void add_binary_indexed_tree(long long pos, long long value, long long dimen)
{
    long long i;
    for(i = pos; i <= index_data_tail; i += (i & -i))
    {
        bit[i].time[dimen] += value;
        bit[i].time[dimen] %= M;
    }
}
long long sum_binary_indexed_tree(long long pos, int dimen)
{
    long long index;
    long long sum = 0;
    for(index = pos; index; index -= (index & -index))
    {
        sum += bit[index].time[dimen];
        sum %= M;
    }
    return sum;
}
int main()
{
    long long index, index2, target_index, d;
    scanf("%lld", &n);
    scanf("%d", &k);
    for(index = 1; index <= n; index++)
    {
        scanf("%lld", &d);
        origin_data[index] = d;
        sort_data[index] = d;
    }
    quicksort(1, n);
    for(index = 1; index <= n; index++)
    {
        if(index == 1) index_data[++index_data_tail] = sort_data[index];
        else
        {
            if(sort_data[index] != index_data[index_data_tail])
                index_data[++index_data_tail] = sort_data[index];
        }
    }
    for(index = n; index >= 1; index--)
    {
        target_index = binary_index(origin_data[index]);
        add_binary_indexed_tree(target_index, 1, 0);
        for(index2 = 0; index2 < k; index2++)
        {
            ans_time[index2] = 0;
            ans_time[index2] = sum_binary_indexed_tree(target_index - 1, index2);
            add_binary_indexed_tree(target_index, ans_time[index2] % M, index2+1);
        }
    }
    printf("%lld", sum_binary_indexed_tree(index_data_tail, k-1) % M);
    return 0;
}
