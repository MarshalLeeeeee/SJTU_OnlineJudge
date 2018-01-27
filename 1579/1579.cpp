#include <stdio.h>
using namespace std;

int str1_len, str2_len;
char str1[1000];
char str2[1000];
int record[1000][1000];

int max_int(int a, int b)
{
    return (a > b ? a : b);
}
int main()
{
    scanf("%d", &str1_len);
    scanf("%d", &str2_len);
    while(getchar() != '\n') continue;//read \n
    int index, index2;
    for(index = 0; index < str1_len; index++)
    {
        str1[index] = getchar();
    }
    while(getchar() != '\n') continue;//read \n
    for(index = 0; index < str2_len; index++)
    {
        str2[index] = getchar();
    }
    for(index = str1_len - 1; index >= 0; index--)
    {
        for(index2 = str2_len - 1; index2 >= 0; index2--)
        {
            if(index == str1_len - 1 && index2 == str2_len - 1)
            {
                if(str1[index] == str2[index2]) record[index][index2] = 1;
                else record[index][index2] = 0;
                continue;
            }
            if(index == str1_len - 1)
            {
                if(record[index][index2+1]) record[index][index2] = 1;
                else
                {
                    if(str1[index] == str2[index2]) record[index][index2] = 1;
                    else record[index][index2] = 0;
                }
                continue;
            }
            if(index2 == str2_len - 1)
            {
                if(record[index+1][index2]) record[index][index2] = 1;
                else
                {
                    if(str1[index] == str2[index2]) record[index][index2] = 1;
                    else record[index][index2] = 0;
                }
                continue;
            }
            if(str1[index] != str2[index2]) record[index][index2] = max_int(record[index+1][index2], record[index][index2+1]);
            else record[index][index2] = 1 + record[index+1][index2+1];
        }
    }
    printf("%d", record[0][0]);
    return 0;
}
