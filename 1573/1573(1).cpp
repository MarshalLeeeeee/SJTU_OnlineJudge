#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main()
{
    ifstream is("5.in");
    ofstream os("check.txt");
    long list_len, color_num;
    cin >> list_len >> color_num;
    long *list, *color;
    long ***record;//store the index accoding to the color and if is even or odd. Start from 1
    long **num, **num2;//store how many nunbers is in one group
    long **sum;
    long index, index2, index3;
    record = new long **[color_num];
    num = new long *[color_num];
    num2 = new long *[color_num];
    sum = new long *[color_num];
    for(index = 0; index < color_num; index++)
    {
        sum[index] = new long[2];
        num[index] = new long[2];
        num2[index] = new long[2];
        record[index] = new long *[2];
        for(index2 = 0; index2 < 2; index2++)
        {
            num2[index][index2] = 0;
            num[index][index2] = 0;
            sum[index][index2] = 0;
        }
    }
    list = new long[list_len];
    color = new long[list_len];
    long long ans = 0;
    for(index = 0; index < list_len; index++)
    {
        cin >> list[index];
    }
    for(index = 0; index < list_len; index++)
    {
        cin >> color[index];
        num[color[index] - 1][(index + 1) % 2]++;
        sum[color[index] - 1][(index + 1) % 2] += list[index];
    }
    for(index = 0; index < color_num; index++)
    {
        for(index2 = 0; index2 < 2; index2++)
        {
            if(num[index][index2])
                record[index][index2] = new long[num[index][index2]];
        }
    }
    for(index = 0; index < list_len; index++)
    {
        record[color[index] - 1][(index + 1) % 2][num2[color[index] - 1][(index + 1) % 2]++] = index + 1;
    }
    for(index = 0; index < color_num; index++)
    {
        for(index2 = 0; index2 < 2; index2++)
        {
            if(num[index][index2] > 1)
            {
                for(index3 = 0; index3 < num[index][index2]; index3++)
                {
                    ans += (long long)record[index][index2][index3] * (long long)list[record[index][index2][index3] - 1] % 10007 * (long long)(num[index][index2] - 1); ans %= 10007;
                    ans += (long long)record[index][index2][index3] * (long long)(sum[index][index2] - list[record[index][index2][index3] - 1]) % 10007; ans %= 10007;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
