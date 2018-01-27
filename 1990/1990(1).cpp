#include <iostream>
#include <stdio.h>
using namespace std;
int num, day;
int fav[2000001];
int index_reflect[2000001];// argument is the index in array fav, and returns the its number according to the initial input
int index_anti_reflect[2000001];
int range[2000001]; int range_tail = 0;
int value[2000001]; int value_tail = 0;

int main()
{
    int i, delta, cnt, mininum, minibound;
    scanf("%d %d", &num, &day);
    for(int index = 1; index <= num; index++)
    {
        scanf("%d", &fav[index]);
        if(index == 1) {mininum = fav[1]; minibound = 1;}
        if(index > 1 && fav[index] == fav[index-1]) minibound++;
        index_reflect[index] = index;
        index_anti_reflect[index] = index;
        //if(index > 1 && fav[index] > fav[index-1]) {value[++value_tail] = fav[index-1]; range[++range_tail] = index-1;}
    }
    for(int index = 0; index < day; index++)
    {
        scanf("%d %d", &i, &delta);
        //printf("%d %d\n", i, delta);
        if(delta == 1)
        {
            int index2, index3;
            int target = fav[index_anti_reflect[i]];
            if(target == mininum) minibound--;
            for(index2 = index_anti_reflect[i]; index2 <= num; index2++)
            {
                if(index2 == num)
                {
                    fav[index2]++;
                    break;
                }
                if(fav[index2+1] == target)
                {
                    index_reflect[index2] = index_reflect[index2+1];
                    index_anti_reflect[index_reflect[index2]] = index2;
                }
                else
                {
                    fav[index2]++;
                    break;
                }
            }
            for(index3 = index2; index3 <= num; index3++)
            {
                if(index3 == num)
                {
                    index_reflect[num] = i;
                    index_anti_reflect[i] = num;
                    break;
                }
                if(fav[index3+1] == fav[index3])
                {
                    index_reflect[index3] = index_reflect[index3+1];
                    index_anti_reflect[index_reflect[index3]] = index3;
                }
                else
                {
                    index_reflect[index3] = i;
                    index_anti_reflect[i] = index3;
                    break;
                }
            }
        }
        else
        {
            int index2, index3;
            int target = fav[index_anti_reflect[i]];
            if(target == mininum) {minibound = 1; mininum = target-1;}
            else if(target == mininum + 1) {minibound++;}
            for(index2 = index_anti_reflect[i]; index2 >= 1; index2--)
            {
                if(index2 == 1)
                {
                    fav[index2]--;
                    index_reflect[1] = i;
                    index_anti_reflect[i] = 1;
                    break;
                }
                if(fav[index2-1] == target)
                {
                    index_reflect[index2] = index_reflect[index2-1];
                    index_anti_reflect[index_reflect[index2]] = index2;
                }
                else
                {
                    fav[index2]--;
                    index_reflect[index2] = i;
                    index_anti_reflect[i] = index2;
                    break;
                }
            }
        }
        //for(int index2 = 1; index2 <= num; index2++)
        //    cout << "Info.: " << fav[index2] << ' ' << index_reflect[index2] << ' ' << index_anti_reflect[index2] << endl;
        if(minibound)
        {
            printf("%d\n", index_reflect[minibound]);
        }
        else
        {
            int index2;
            for(index2 = 1; index2 <= num; index2++)
            {
                if(index2 == num) {printf("%d\n", index_reflect[index2]);break;}
                else if(fav[index2] == fav[index2+1]) continue;
                else {printf("%d\n", index_reflect[index2]);break;}
            }
            mininum = fav[1];
            minibound = index2;
        }
        //cout << "mininum and minibound:" << mininum << ' ' << minibound << endl;
    }
    return 0;
}
