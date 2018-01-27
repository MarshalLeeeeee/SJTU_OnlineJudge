#include <iostream>

using namespace std;

int k, p, q, digit = 0;
long long l, r, count = 0;
long long exp[90] = {0};
bool flag[90] = {0};
long long ans[90];
long long ans_len = 0;

long long quick_pow(int k, int n)
{
    if(k == 0) return 0;
    else if(k == 1) return n;
    else
    {
        long long tmp;
        tmp = quick_pow(k/2, n);
        if(k % 2 == 0) return tmp*tmp;
        else return tmp*tmp*n;
    }
}
void digit_sum(long long n)
{
    if(!(n/10))
    {
        digit += n % 10;
        return ;
    }
    else
    {
        digit = digit + n % 10;
        digit_sum(n/10);
        return ;
    }
}
void push(long long value)
{
    ans[ans_len++] = value;
}
void quick_sort(long long *, long long, long long);
int main()
{
    cin >> k >> p >> q;
    cin >> l >> r;
    int index;
    long long tmp;
    for(index = 0; index <= 81; index++)
    {
        //cout << index << endl;
        digit = 0;//cout << index << ' ';
        tmp = quick_pow(k, index) * p + q;//cout << tmp << ' ';
        digit_sum(tmp);//cout << digit << endl;
        if(digit == index && (l <= tmp && tmp <= r))
            push(tmp);
    }
    cout << ans_len << endl;
    if(!ans_len)
    {
        cout << -1;
    }
    else
    {
        quick_sort(ans, 0, ans_len - 1);
        for(index = 0; index < ans_len; index++)
        {
            cout << ans[index] << ' ';
        }
    }
    return 0;
}
void quick_sort(long long *ans, long long start, long long end)
{
    if(start >= end) return ;
    long long pivot = ans[start];
    long long tmp;
    long long left, right;
    for(left = start + 1; left <= end; left++)
    {
        if(ans[left] > pivot) break;
    }
    for(right = left + 1; right <= end; right++)
    {
        if(ans[right] < pivot)
        {
            tmp = ans[left];
            ans[left] = ans[right];
            ans[right] = tmp;
            left++;
        }
    }
    ans[start] = ans[left - 1];
    ans[left - 1] = pivot;
    quick_sort(ans, start, left - 2);
    quick_sort(ans, left, end);
}
