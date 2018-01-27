#include <stdio.h>
using namespace std;
struct Node
{
    long long begin;
    long long end;
};
long long num;
Node data[5001];
long long begin_stack[5001]; long long begin_tail = -1;
long long end_stack[5001]; long long end_tail = -1;
long long occupy = 0, vacancy = 0;
void quicksort(int ibegin, int iend)
{
    if(ibegin >= iend) return ;
    long long pivot = data[ibegin].begin, tmp1, tmp2;
    int left, right;
    for(left = ibegin; left <= iend; left++)
    {
        if(data[left].begin > pivot) break;
    }
    for(right = left+1; right <= iend; right++)
    {
        if(data[right].begin < pivot)
        {
            tmp1 = data[left].begin; tmp2 = data[left].end;
            data[left].begin = data[right].begin; data[left].end = data[right].end;
            data[right].begin = tmp1; data[right].end = tmp2;
            left++;
        }
    }
    tmp1 = data[left-1].begin; tmp2 = data[left-1].end;
    data[left-1].begin = data[ibegin].begin; data[left-1].end = data[ibegin].end;
    data[ibegin].begin = tmp1; data[ibegin].end = tmp2;
    quicksort(ibegin, left-2);
    quicksort(left, iend);
}

int main()
{
    scanf("%lld", &num);
    for(int index = 0; index < num; index++)
        scanf("%lld %lld", &data[index].begin, &data[index].end);
    quicksort(0, num-1);
    for(int index = 0; index < num; index++)
    {
        if(index == 0)
        {
            begin_stack[++begin_tail] = data[index].begin;
            end_stack[++end_tail] = data[index].end;
            occupy = data[index].end - data[index].begin;
        }
        else
        {
            if(data[index].begin > end_stack[end_tail])
            {
                begin_stack[++begin_tail] = data[index].begin;
                end_stack[++end_tail] = data[index].end;
                if(vacancy < data[index].begin - end_stack[end_tail-1]) vacancy = data[index].begin - end_stack[end_tail-1];
                if(occupy < data[index].end - begin_stack[begin_tail]) occupy = data[index].end - begin_stack[begin_tail];
            }
            else
            {
                if(data[index].end > end_stack[end_tail])
                {
                    end_stack[++end_tail] = data[index].end;
                    if(occupy < end_stack[end_tail] - begin_stack[begin_tail]) occupy = data[index].end - begin_stack[begin_tail];
                }
            }
        }
    }
    printf("%lld %lld", occupy, vacancy);
    return 0;
}
