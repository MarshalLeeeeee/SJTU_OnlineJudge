#include <iostream>
#include <list>
using namespace std;

struct locate
{
    int x;
    int y;
    locate(int xx, int yy):x(xx), y(yy){}
};
int count = 0;
list<locate> safe;
list<locate> unsafe;
bool exam_safe(int **, int, int);
int return_ans(int **);
int main()
{
    int len;
    cin >> len;
    int **ptr;
    int index, index2;
    ptr = new int *[len+2];
    for(index = 0; index < len+2; index++)
    {
        ptr[index] = new int[len+2];
    }
    for(index = 1; index <= len; index++)
    {
        for(index2 = 1; index2 <= len; index2++)
        {
            cin >> ptr[index][index2];
            if(!ptr[index][index2]) safe.push_back(locate(index, index2));
        }
    }
    for(index = 0; index < len + 2; index++)
    {
        ptr[0][index] = 2;
        ptr[len + 1][index] = 2;
        ptr[index][0] = 2;
        ptr[index][len + 1] = 2;
    }
    cout << return_ans(ptr);
    return 0;
}
bool exam_safe(int **ptr, int x, int y)
{
    if(ptr[x-1][y] == 1 || ptr[x+1][y] == 1 || ptr[x][y-1] == 1 || ptr[x][y+1] == 1) return 0;
    else return 1;
}
int return_ans(int **ptr)
{
    list<locate>::iterator itrs, itre, itrend = safe.end();
    while(!safe.empty())
    {
        for(itrs = safe.begin(); itrs != itrend;)
        {
            if(!exam_safe(ptr, (*itrs).x, (*itrs).y))
            {
                itre = itrs++;
                unsafe.push_back(*itre);
                safe.erase(itre);
            }
            else itrs++;
        }
        count++;
        for(itrs = unsafe.begin(); itrs != unsafe.end(); itrs++)
        {
            ptr[(*itrs).x][(*itrs).y] = 1;
        }
        unsafe.clear();
    }
    return count;
}
