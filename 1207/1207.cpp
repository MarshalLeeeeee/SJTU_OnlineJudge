#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>

using namespace std;
long long coach[20000];
int coach_head = 0, coach_tail = 0;
long long coach_wait = 0;
long long lorry[20000];
int lorry_head = 0, lorry_tail = 0;
long long lorry_wait = 0;
int ferry_num = 0;

int main()
{
    //ifstream fin("read.txt");
    int num;
    scanf("%d", &num);
    //fin >> num;
    int index, index2, index3;
    int choice;
    for(index = 0; index < num; index++)
    {
        scanf("%d", &choice);
        //fin >> choice;
        if(choice)
        {
            scanf("%lld", &lorry[lorry_tail++]);
            //fin >> lorry[lorry_tail++];
        }
        else
        {
            scanf("%lld", &coach[coach_tail++]);
            //fin >> coach[coach_tail++];
        }
    }
    while(coach_head != coach_tail || lorry_head != lorry_tail)
    {
        for(index2 = 0; index2 < 2; index2++)
        {
            for(index = 0; index < 4 && coach_head != coach_tail; index++)
            {
                if(coach[coach_head] <= ferry_num * 10)
                    coach_wait += -coach[coach_head++] + (ferry_num) * 10;
                else break;
            }
            for(index3 = index; index3 < 5 && lorry_head != lorry_tail; index3++)
            {
                if(lorry[lorry_head] <= ferry_num * 10)
                    lorry_wait += -lorry[lorry_head++] + (ferry_num) * 10;
                else break;
            }
        }
        ferry_num++;
    }
    cout << fixed << setprecision(3) << (float)coach_wait / coach_tail << ' ';
    cout << fixed << setprecision(3) << (float)lorry_wait / lorry_tail;
    return 0;
}
