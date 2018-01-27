#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void quick_sort(unsigned long *, unsigned long *, unsigned long, unsigned long);
void quick_sort(long long *, long *, long, long);
long long inversion_pair(long *, long);
void binary_indexed_tree_add(long *, long, long, long);
long binary_indexed_tree_sum(long *, long);
void insert_sort(long long *, unsigned long *, unsigned long);

int main()
{
    ifstream is("save.txt");
    long n;
    cin >> n;
    //is >> n;
    long long *value1, *value2;
    value1 = new long long[n];
    value2 = new long long[n];
    long index;
    for(index = 0; index < n; index++)
    {
        cin >> value1[index];
        //is >> value1[index];
        //cout << value1[index] << endl;
    }
    for(index = 0; index < n; index++)
    {
        cin >> value2[index];
        //is >> value2[index];
        //cout << value2[index] << endl;
    }
    //for(index = 0; index < n; index++)
    //    cout << value1[index] << ' ' << value2[index] << endl;
    long *order1, *order2, *order;
    order1 = new long[n];for(index = 0; index < n; index++){order1[index] = index;}
    order2 = new long[n];for(index = 0; index < n; index++){order2[index] = index;}
    order = new long[n];
    quick_sort(value1, order1, 0, n - 1);
    /*for(index = 0; index < n; index++) cout << order1[index] << ' ';
    cout << endl;*/
    quick_sort(value2, order2, 0, n - 1);
    //for(index = 0; index < n; index++)
    //    cout << order1[index] << ' ' << order2[index] << endl;
    //cout << endl;
    for(index = 0; index < n; index++)
    {
        order[order1[index]] = order2[index];
    }
    //for(index = 0; index < n; index++)
    //    cout << order[index] << ' ';
    //cout << endl;
    cout << inversion_pair(order, n);
    return 0;
}
void quick_sort(unsigned long *arr1, unsigned long *arr2, unsigned long start, unsigned long end)
{
    //cout << start << ' ' << end << endl;
    if(start >= end) return ;
    unsigned long pivot = arr1[start];    unsigned long i, j;
    unsigned long tmp1, tmp2;
    for(i = start + 1; i <= end; i++)
    {
        if(arr1[i] > pivot) break;
    }
    for(j = i + 1; j <= end; j++)
    {
        if(arr1[j] < pivot)
        {
            tmp1 = arr1[j];
            arr1[j] = arr1[i];
            arr1[i] = tmp1;
            tmp2 = arr2[j];
            arr2[j] = arr2[i];
            arr2[i] = tmp2;
            i++;
        }
    }
    arr1[start] = arr1[i - 1];
    arr1[i - 1] = pivot;
    tmp2 = arr2[start];
    arr2[start] = arr2[i - 1];
    arr2[i - 1] = tmp2;
    if(i >= 2) quick_sort(arr1, arr2, start, i - 2);
    quick_sort(arr1, arr2, i, end);
}
void quick_sort(long long *arr1, long *arr2, long start, long end)
{
    //cout << start << ' ' << end << endl;
    if(start >= end) return ;
    long long pivot = arr1[start];
    long i, j, m;
    long long tmp1;
    long tmp2;
    for(i = start + 1; i <= end; i++)
    {
        if(arr1[i] > pivot) break;
    }
    for(j = i + 1; j <= end; j++)
    {
        if(arr1[j] < pivot)
        {
            tmp1 = arr1[j];
            arr1[j] = arr1[i];
            arr1[i] = tmp1;
            tmp2 = arr2[j];
            arr2[j] = arr2[i];
            arr2[i] = tmp2;
            i++;
        }
    }
    for(j = start, m = start; j < i; j++)
    {
        if(arr1[j] == arr1[i - 1])
        {
            arr1[m] = arr1[j];
            arr1[j] = pivot;
            tmp2 = arr2[j];
            arr2[j] = arr2[m];
            arr2[m] = tmp2;
            m = j;
        }
    }
    if(i >= 2) quick_sort(arr1, arr2, start, i - 2);
    quick_sort(arr1, arr2, i, end);
}
long long inversion_pair(long *arr, long len)
{
    long *ptr;
    ptr = new long[len];
    long index;
    long long sum = 0;
    for(index = 0; index < len; index++)
    {
        ptr[index] = 0;
    }
    for(index = len - 1; index >= 0; index--)
    {
        //cout << arr[index - 1] << endl;
        sum += binary_indexed_tree_sum(ptr, arr[index]);
        binary_indexed_tree_add(ptr, arr[index], len, 1);
    }
    //cout << sum << endl;
    delete []ptr;
    return sum % 99999997;
}
void binary_indexed_tree_add(long *arr, long pos, long len, long value)
{
    long index;
    for(index = pos + 1; index <= len; index += (index & -index))
    {
        arr[index - 1] += value;
    }
}
long binary_indexed_tree_sum(long *arr, long len)
{
    long index;
    long sum = 0;
    for(index = len; index; index -= (index & -index))
    {
        sum += arr[index - 1];
    }
    return sum;
}
void insert_sort(long long *arr, unsigned long *order, unsigned long len)
{
    unsigned long index1, index2;
    long long tmp1;
    unsigned long tmp2;
    for(index1 = 0; index1 < len; index1++)
    {
        if(index1 == 0) continue;
        for(index2 = index1; index2 >= 1; index2--)
        {
            if(arr[index2 - 1] > arr[index2])
            {
                tmp1 = arr[index2 - 1];
                arr[index2 - 1] = arr[index2];
                arr[index2] = tmp1;
                tmp2 = order[index2 - 1];
                order[index2 - 1] = order[index2];
                order[index2] = tmp2;
            }
            else break;
        }
    }
}
