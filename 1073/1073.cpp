#include <stdio.h>
using namespace std;
struct Node
{
    long long value;
    long long left;
    long long right;
};
struct Point
{
    long long data;
    int i;
};
int num;
Point point[101];
Node ball[101];
long long ans = 0;
void quicksort(int ibegin, int iend)
{
    if(ibegin >= iend) return ;
    long long pivot = point[ibegin].data, tmp1;
    int left, right, tmp2;
    for(left = ibegin; left<= iend; left++)
    {
        if(pivot < point[left].data) break;
    }
    for(right = left + 1; right <= iend; right++)
    {
        if(pivot > point[right].data)
        {
            tmp1 = point[right].data; tmp2 = point[right].i;
            point[right].data = point[left].data; point[right].i = point[left].i;
            point[left].data = tmp1; point[left].i = tmp2;
            left++;
        }
    }
    tmp1 = point[left-1].data; tmp2 = point[left-1].i;
    point[left-1].data = point[ibegin].data; point[left-1].i = point[ibegin].i;
    point[ibegin].data = tmp1; point[ibegin].i = tmp2;
    quicksort(ibegin, left-2);
    quicksort(left, iend);
}
int return_index(long long value)
{
    //to point
    int left = 0, right = num-1, mid;
    while(left <= right)
    {
        mid = (right+left) / 2;
        if(point[mid].data < value) left = mid+1;
        else if(point[mid].data > value) right = mid-1;
        else return mid;
    }
}
int main()
{
    scanf("%d", &num);
    for(int index = 0 ;index < num; index++)
    {
        scanf("%lld", &point[index].data);
        point[index].i = index;
        //printf("%d %lld %d\n", index, point[index].data, point[index].i);
    }
    for(int index = 0; index < num; index++)
    {
        ball[index].value = point[index].data;

        if(index == 0) ball[index].left = point[num-1].data;
        else ball[index].left = point[(index-1)%num].data;

        if(index == num-1) ball[index].right = point[0].data;
        else ball[index].right = point[(index+1)%num].data;

        //printf("%lld %lld %lld\n", ball[index].left, ball[index].value, ball[index].right);
    }
    quicksort(0,num-1);
    //for(int index = 0; index < num; index++) printf("%lld %d\n", point[index].data,point[index].i);
    int right_index, left_index;
    for(int index = 0; index < num-1; index++)
    {
        //printf("%lld %lld %lld\n", ball[point[index].i].left, ball[point[index].i].value, ball[point[index].i].right);
        ans += ball[point[index].i].value * ball[point[index].i].left * ball[point[index].i].right;
        right_index = return_index(ball[point[index].i].right);
        left_index = return_index(ball[point[index].i].left);
        //printf("%d %d %lld %lld\n", right_index, left_index, point[right_index].data, point[left_index].data);
        ball[point[right_index].i].left = ball[point[index].i].left;
        ball[point[left_index].i].right = ball[point[index].i].right;
    }
    printf("%lld", ans);
    return 0;
}
