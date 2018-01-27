#include <stdio.h>
using namespace std;

int order_num;
int set_list[1000];
int save[1000];
int cross[1000];
int set_len = 0;

void quick_sort(int ibegin, int iend)
{
    if(ibegin >= iend) return ;
    int pivot = set_list[ibegin];
    int tmp;
    int left, right;
    for(left = ibegin; left <= iend; left++)
    {
        if(set_list[left] > pivot) break;
    }
    for(right = left + 1; right <= iend; right++)
    {
        if(set_list[right] < pivot)
        {
            tmp = set_list[right];
            set_list[right] = set_list[left];
            set_list[left] = tmp;
            left++;
        }
    }
    set_list[ibegin] = set_list[left - 1];
    set_list[left - 1] = pivot;
    quick_sort(ibegin, left - 2);
    quick_sort(left, iend);
}
int binary_index(int value)
{
    int left = 0, right = set_len - 1, mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(value > set_list[mid])
        {
            left = mid + 1;
        }
        else if(value < set_list[mid])
        {
            right = mid - 1;
        }
        else return mid;
    }
    return -1;
}
int main()
{
    scanf("%d", &order_num);
    int index, index2, index3, index_save;
    int num;
    char ch;
    for(index = 0; index < order_num; index++)
    {
        while(getchar() != '\n') continue;
        scanf("%c", &ch);
        scanf("%d", &num);
        switch(ch)
        {
        case '+':
            {
                for(index2 = 0; index2 < num; index2++)
                {
                    scanf("%d", &set_list[set_len++]);
                }
                quick_sort(0, set_len - 1);
                for(index2 = 0, index_save = 0; index2 < set_len; index2++)
                {
                    if(index2 == 0) save[index_save++] = set_list[index2];
                    else
                    {
                        if(save[index_save-1] != set_list[index2])
                        {
                            save[index_save++] = set_list[index2];
                        }
                    }
                }
                for(index2 = 0; index2 < index_save; index2++)
                {
                    set_list[index2] = save[index2];
                    printf("%d ", set_list[index2]);
                }
                printf("\n");
                set_len = index_save;
                break;
            }
        case '-':
            {
                int d, target;
                for(index2 = 0; index2 < num; index2++)
                {
                    scanf("%d", &d);
                    target = binary_index(d);
                    if(target != -1)
                    {
                        for(index3 = target; index3 < set_len - 1; index3++) set_list[index3] = set_list[index3+1];
                        set_len--;
                    }
                }
                for(index3 = 0; index3 < set_len; index3++)
                    printf("%d ", set_list[index3]);
                printf("\n");
                break;
            }
        case '*':
            {
                int d, target, cross_len = 0;
                for(index2 = 0; index2 < num; index2++)
                {
                    scanf("%d", &d);
                    target = binary_index(d);
                    if(target != -1)
                    {
                        cross[cross_len++] = target;
                    }
                }
                for(index3 = 0; index3 < cross_len; index3++)
                {
                    save[index3] = set_list[cross[index3]];
                }
                for(index3 = 0; index3 < cross_len; index3++)
                {
                    set_list[index3] = save[index3];
                }
                set_len = cross_len;
                quick_sort(0, set_len - 1);
                for(index3 = 0; index3 < set_len; index3++) printf("%d ", set_list[index3]);
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
