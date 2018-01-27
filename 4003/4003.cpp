#include <stdio.h>
using namespace std;
long long bottle;
int group;

int return_high(long long value)
{
    int ans = 0;
    while(value)
    {
        value -= (value & -value);
        ans++;
    }
    return ans;
}

int main()
{
    int high;
    scanf("%lld %d", &bottle, &group);
    high = return_high(bottle);
    if(high <= group) printf("0");
    else
    {
        int ans = 0;
        while(high > group)
        {
            ans += bottle & -bottle;
            bottle += bottle & -bottle;
            high = return_high(bottle);
        }
        printf("%d", ans);
    }
    return 0;
}
