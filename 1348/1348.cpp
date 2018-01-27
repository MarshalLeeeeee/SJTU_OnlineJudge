#include <iostream>
#include <iomanip>
#include <stdio.h>
#define LEN 1000000
#define MLEN 10001

using namespace std;

long long boy_queue[LEN];
long long boy_head = 0, boy_tail = 0;
long long girl_queue[LEN];
long long girl_head = 0, girl_tail = 0;
long long student_num;
long long music[MLEN];
long long music_num;
long long boy_wait = 0, girl_wait = 0;

int main()
{
    long long index;
    int choice;
    scanf("%lld", &music_num);
    //cout << music_num << endl;
    music[0] = 0;
    long long sum = 0;
    for(index = 1; index <= music_num; index++)
    {
        scanf("%lld", &music[index]);
        music[index] += sum;
        sum += music[index];
    }
    scanf("%lld", &student_num);
    //cout << student_num << endl;
    for(index = 0; index < student_num; index++)
    {
        scanf("%d", &choice);
        if(choice == 1) scanf("%lld", &boy_queue[boy_tail++]);
        else scanf("%lld", &girl_queue[girl_tail++]);
    }
    cout << boy_tail << ' ' << girl_tail << endl;
    for(index = 0; index <= music_num && (boy_head != boy_tail && girl_head != girl_tail); index++)
    {
        while((boy_queue[boy_head] <= music[index] && girl_queue[girl_head] <= music[index]) && (boy_head != boy_tail && girl_head != girl_tail))
        {
            //cout << index << ' ' << boy_head << ' ' << girl_head << endl;
            boy_wait += music[index] - boy_queue[boy_head];//cout << boy_wait << ' ';
            girl_wait += music[index] - girl_queue[girl_head];//cout << girl_wait << endl;
            boy_head++;
            girl_head++;
        }
    }
    while(boy_head != boy_tail)
    {
        boy_wait += music[music_num] - boy_queue[boy_head++];
    }
    while(girl_head != girl_tail)
    {
        girl_wait += music[music_num] - girl_queue[girl_head++];
    }
    //cout << boy_wait << ' ' << girl_wait << endl;
    printf("%.2f %.2f", (float)boy_wait / boy_tail, (float)girl_wait / girl_tail);
    return 0;
}
