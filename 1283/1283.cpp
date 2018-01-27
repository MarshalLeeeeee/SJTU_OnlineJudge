#include <stdio.h>
using namespace std;
int num, read_num;
long long pow = 0;
int t[1001] = {0};
int cnt[1001];
int ans[2][10000] = {0};
int ans_len[2] = {0};
int ans_flag = 0;
void com(int a, int b)
{
    int curr_a = a, curr_b = b;
    while(t[curr_a] > 0) curr_a = t[curr_a];
    while(t[curr_b] > 0) curr_b = t[curr_b];
    if(curr_a == curr_b) return ;
    if(t[curr_a] < t[curr_b]) {cnt[-1*t[curr_a]]--; cnt[-1*t[curr_b]]--; t[curr_a] += t[curr_b]; t[curr_b] = curr_a; cnt[-1*t[curr_a]]++;}
    else {cnt[-1*t[curr_a]]--; cnt[-1*t[curr_b]]--; t[curr_b] += t[curr_a]; t[curr_a] = curr_b; cnt[-1*t[curr_b]]++;}
}
void quicksort(int ibegin, int iend)
{
    if(ibegin >= iend) return ;
    int pivot = t[ibegin], tmp;
    int left, right;
    for(left = ibegin; left <= iend; left++)
    {
        if(t[left] > pivot) break;
    }
    for(right = left + 1; right <= iend; right++)
    {
        if(t[right] < pivot)
        {
            tmp = t[right];
            t[right] = t[left];
            t[left] = tmp;
            left++;
        }
    }
    t[ibegin] = t[left-1];
    t[left-1] = pivot;
    quicksort(ibegin, left-2);
    quicksort(left, iend);
}
void mult(void)
{
    int digit, add = 0;
    for(int index = 0; index < ans_len[ans_flag]; index++)
    {
        digit = 2 * ans[ans_flag][index] + add;
        add = digit / 10;
        digit %= 10;
        ans[ans_flag^1][index] = digit;
    }
    if(add) {ans[ans_flag^1][ans_len[ans_flag]] = 1; ans_len[ans_flag^1] = ans_len[ans_flag] + 1;}
    else ans_len[ans_flag^1] = ans_len[ans_flag];
    ans_flag ^= 1;
}

int main()
{
    int a, b;
    scanf("%d %d", &num, &read_num);
    for(int index = 1; index <= num; index++) cnt[index] = 0;
    cnt[1] = num;
    for(int index = 0; index <= num; index++)
        t[index] = -1;
    for(int index = 1; index <= read_num; index++)
    {
        scanf("%d %d", &a, &b);
        com(a, b);
    }
    quicksort(1, num);
    for(int index = 1; index <= num; index++)
    {
        if(t[index] >= -1) break;
        pow += (t[index]+1) * (-1);
    }
    ans[0][0] = 1; ans_len[0] = 1;
    while(pow--)
    {
        mult();
    }
    for(int index = ans_len[ans_flag]-1; index >= 0; index--) printf("%d", ans[ans_flag][index]);
    return 0;
}
