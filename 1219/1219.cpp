#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

long long seq[200001];
long long seq_copy[400002];
long long seq_copy_len = 0;
long long seq_index[400002];
long long seq_index_len = 0;//BIT's num
long long indexed_tree[1000001] = {0};
long long sum[1000001] = {0};
long long len;
long long sup = 0;
long long ans = 0;

void add_indexed_tree(long long value, long long x)
{
    long long i;
    for(i = x; i <= seq_index_len; i += (i & -i))
    {
        indexed_tree[i] += value;
    }
}
long long sum_indexed_tree(long long x)
{
    long long sum = 0, i;
    for(i = x; i; i -= (i & -i))
    {
        sum += indexed_tree[i];
    }
    return sum;
}
void quick_sort(long long starti, long long endi)
{
    if(starti >= endi) return ;
    long long pivot = seq_copy[starti], tmp;
    long long left, right;
    for(left = starti + 1; left <= endi; left++)
    {
        if(pivot < seq_copy[left]) break;
    }
    for(right = left+1; right <= endi; right++)
    {
        if(pivot > seq_copy[right])
        {
            tmp = seq_copy[right];
            seq_copy[right] = seq_copy[left];
            seq_copy[left] = tmp;
            left++;
        }
    }
    seq_copy[starti] = seq_copy[left - 1];
    seq_copy[left - 1] = pivot;
    quick_sort(starti, left - 2);
    quick_sort(left, endi);
}
long long return_index(long long x)
{
    long long right = 0;
    long long left = seq_index_len-1;
    while(right < left)
    {
        if(seq_index[(right+left)/2] == x) return (right+left)/2+1;
        else if(seq_index[(right+left)/2] > x) left = (right+left)/2-1;
        else right = (right+left)/2+1;
    }
    return right+1;
}

int main()
{
    //ifstream fin("save.txt");
    scanf("%lld", &len);
    //fin >> len;
    long long index;
    long long tmp;
    for(index = 0; index < len; index++)
    {
        scanf("%lld", &seq[index]);
        seq_copy[seq_copy_len++] = seq[index];
        seq_copy[seq_copy_len++] = seq[index] * 2;
        //fin >> seq[index];
    }
    quick_sort(0, seq_copy_len-1);
    for(index = 0; index < seq_copy_len; index++)
    {
        if(!seq_index_len) seq_index[seq_index_len++] = seq_copy[index];
        else
        {
            if(seq_copy[index] != seq_index[seq_index_len-1])
            {
                seq_index[seq_index_len++] = seq_copy[index];
            }
        }
    }
    //for(index = 0; index < seq_index_len; index++) cout << seq_index[index] << endl;
    //cout << return_index(18) << ' ' << return_index(3) << endl;
    for(index = len-1; index >= 0; index--)
    {
        if(seq[index] == seq_index[0])
        {
            add_indexed_tree(1, return_index(2*seq[index]));
        }
        else
        {
            ans+=sum_indexed_tree(return_index(seq[index])-1);
            add_indexed_tree(1, return_index(2*seq[index]));
        }
    }
    cout << ans;

    return 0;
}
