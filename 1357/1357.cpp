#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int xx = 0, int yy = 0):x(xx), y(yy){}
    bool operator==(Point &p)
    {
        if(x == p.x && y == p.y) return 1;
        else return 0;
    }
};

bool map[5][5] = {0};
Point path[7];
bool path_flag[7] = {0};
int path_len = 0;
int count = 0;

bool in(Point *, Point, int);
void push(Point);
void pop(void);
void exam_path(void);
bool distance(Point, Point, int);
bool link(void);

int main(void)
{
    char read;
    int index, index2, index3, index4, index5, index6, index7;
    for(index = 0; index < 5; index++)
    {
        for(index2 = 0; index2 < 5; index2++)
        {
            cin.get(read);
            if(read == 'J') map[index][index2] = 1;
            else if(read == '\n') index2--;
        }
    }
    for(index = 0; index < 19; index++)
    {
        push(Point(index/5, index%5));
        for(index2 = index + 1; index2 < 20; index2++)
        {
            push(Point(index2/5, index2%5));
            for(index3 = index2 + 1; index3 < 21; index3++)
            {
                push(Point(index3/5, index3%5));
                for(index4 = index3 + 1; index4 < 22; index4++)
                {
                    push(Point(index4/5, index4%5));
                    for(index5 = index4 + 1; index5 < 23; index5++)
                    {
                        push(Point(index5/5, index5%5));
                        for(index6 = index5 + 1; index6 < 24; index6++)
                        {
                            push(Point(index6/5, index6%5));
                            for(index7 = index6 + 1; index7 < 25; index7++)
                            {
                                push(Point(index7/5, index7%5));
                                exam_path();
                                pop();
                            }
                            pop();
                        }
                        pop();
                    }
                    pop();
                }
                pop();
            }
            pop();
        }
        pop();
    }
    cout << count;
    return 0;
}
void push(Point p)
{
    path[path_len++] = p;
}
void pop(void)
{
    path_len--;
}
void exam_path(void)
{
    int index, index2, sum = 0;
    int flag = 1;
    flag = link();
    for(index = 0; index < 7; index++)
    {
        sum += map[path[index].x][path[index].y];
    }
    if(flag)
    {

        if(sum >= 4)
        {
            count++;
        }
    }
}
bool distance(Point a, Point b, int d)
{
    if(abs(a.x - b.x) + abs(a.y - b.y) == d) return 1;
    else return 0;
}
bool link(void)
{
    Point link_path[7];
    int len = 0, curr = 0;
    int flag;
    link_path[len++] = path[0];
    int index;
    while(curr != len)
    {
        for(index = 0; index < 7; index++)
        {
            if(in(link_path, path[index], len)) continue;
            else
            {
                if(distance(link_path[curr], path[index],1))
                {
                    link_path[len++] = path[index];
                }
            }
        }
        curr++;
    }
    if(len == 7)return 1;
    else return 0;

}
bool in(Point *ptr, Point p, int len)
{
    int index;
    for(index = 0; index < len; index++)
    {
        if(ptr[index] == p) return 1;
    }
    return 0;
}
