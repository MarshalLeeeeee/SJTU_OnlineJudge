#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

long long seq[200001];
long long indexed_tree[1000001] = {0};
long long sum[1000001] = {0};
long long len;
long long sup = 0;
long long ans = 0;

void add_indexed_tree(long long value, long long x)
{
    long long i;
    for(i = x; i <= sup; i += (i & -i))
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

int main()
{
    ifstream fin("save.txt");
    //scanf("%lld", &len);
    fin >> len;
    long long index;
    long long tmp;
    for(index = 1; index <= len; index++)
    {
        //scanf("%lld", &seq[index]);
        fin >> seq[index];
        if(seq[index] > sup) sup = seq[index];
    }
    sup = (sup - 1) / 2;

    for(index = len; index >= 1; index--)
    {
        tmp = seq[index];
        if(tmp > sup)//not add_indexed_tree
        {
            if(tmp > 2) ans += sum_indexed_tree((tmp - 1) / 2);
        }
        else
        {
            if(tmp > 2) ans += sum_indexed_tree((tmp - 1) / 2);
            add_indexed_tree(1, tmp);
        }
    }
    cout << ans;
    return 0;
}
