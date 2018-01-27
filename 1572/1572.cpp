#include <iostream>
#define MAX 5

using namespace std;

void binary_indexed_tree_add(long *, long, long, long);
long binary_indexed_tree_sum(const long *, long);
long inversion_pair(const long *, long);

int main()
{
    long num;
    cin >> num;
    long *arr;
    arr = new long[num];
    long index;
    for(index = 0; index < num; index++)
    {
        cin >> arr[index];
    }
    cout << inversion_pair(arr, num) << endl;
    return 0;
}
long inversion_pair(const long *arr, long len)
{
    long *record;
    record = new long[len];
    long index;
    for(index = 0; index < len; index++)
    {
        record[index] = 0;
    }
    long ans = 0;
    for(index = len - 1; index >= 0; index--)
    {
        ans += binary_indexed_tree_sum(record, arr[index] - 1);
        binary_indexed_tree_add(record, arr[index] - 1, 1, len);
    }
    return ans;
}
void binary_indexed_tree_add(long *arr, long pos, long value, long len)
{
    long index;
    for(index = pos + 1; index <= len; index += (index & -index))
    {
        arr[index - 1] += value;
    }
}
long binary_indexed_tree_sum(const long *arr, long num)
{
    long index;
    long sum = 0;
    for(index = num; index; index -= (index & -index))
    {
        sum += arr[index - 1];
    }
    return sum;
}
