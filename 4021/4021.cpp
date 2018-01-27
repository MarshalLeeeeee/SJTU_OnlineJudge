#include <stdio.h>
#define minn(a,b) (a)<(b)?(a):(b)
using namespace std;
struct Magic
{
    long long cost;
    long long damage;
};
Magic single[100];
long long single_len = 0;
Magic all[100];
long long all_len = 0;
long long hp[100];
long long max_hp = 0;
long long single_cost[100001];
long long all_cost[100001];
long long monster_num;
long long magic_num;
long long min_cost = 0;

void min_single_cost(long long value)
{
    long long index, index2;
    for(index = 0; index < single_len; index++)
    {
        if(index == 0)
        {
            for(index2 = 1; index2 <= value; index2++)
            {
                single_cost[index2] = ((index2 - 1) / single[index].damage + 1) * single[index].cost;
            }
        }
        else
        {
            for(index2 = 1; index2 <= value; index2++)
            {
                if(index2 - single[index].damage < 0)
                {
                    single_cost[index2] = minn(single_cost[index2], single[index].cost);
                }
                else
                {
                    single_cost[index2] = minn(single_cost[index2], single_cost[index2-single[index].damage] + single[index].cost);
                }
            }
        }
    }
}
long long min_all_cost(void)
{
    long long index, index2;
    long long max_hp = 0;
    long long min_costs;
    long long costs = 0;
    long long tmp;
    if(single_len)
    {
        for(index2 = 0; index2 < monster_num; index2++)//the monster number [1,100]
        {
            if(hp[index2] > 0)
                costs += single_cost[hp[index2]];
        }
        min_costs = costs;//initial min_costs as the current cost without AOE
        if(min_costs == 0) return 0;
        for(index = 0; index < all_len; index++)//if all_len is 0, return min_costs directly
        {
            for(index2 = 0; index2 < monster_num; index2++)
            {
                hp[index2] -= all[index].damage;
                if(hp[index2] > max_hp) max_hp = hp[index2];
            }
            tmp = min_all_cost();
            if(tmp + all[index].cost < min_costs) min_costs = tmp + all[index].cost;
            for(index2 = 0; index2 < monster_num; index2++)
            {
                hp[index2] += all[index].damage;
            }
        }
        return min_costs;
    }
    else
    {
        for(index2 = 0; index2 < monster_num; index2++)//the monster number [1,100]
        {
            if(hp[index2] > 0)
            {
                costs = 1;
                break;
            }
        }
        if(!costs) return 0;
        for(index = 0; index < all_len; index++)//if all_len is 0, return min_costs directly
        {
            for(index2 = 0; index2 < monster_num; index2++)
            {
                hp[index2] -= all[index].damage;
                if(hp[index2] > max_hp) max_hp = hp[index2];
            }
            if(index == 0) min_costs = all[index].cost + min_all_cost();
            else
            {
                tmp = all[index].cost + min_all_cost();
                if(tmp < min_costs) min_costs = tmp;
            }
            for(index2 = 0; index2 < monster_num; index2++)
            {
                hp[index2] += all[index].damage;
            }
        }
        return min_costs;
    }
}


int main()
{
    long long index, tmp, d;
    char name[40];
    char choice[10];
    scanf("%lld", &monster_num);//input the number of monster [1, 100]
    for(index = 0; index < monster_num; index++)
    {
        scanf("%lld", &hp[index]);//input the hp [1,100000]
        if(max_hp < hp[index]) max_hp = hp[index];//record the max of hp(over 0 for sure)
    }
    scanf("%lld", &magic_num);//input the magic number [1,100]
    for(index = 0; index < magic_num; index++)
    {
        scanf("%s", name);//name of magic
        scanf("%lld", &tmp);//cost of magic
        scanf("%s", choice);//whether single or all
        scanf("%lld", &d);//damage of cost
        if(d == 0) continue;//damage is 0, thus not record it
        if(choice[0] == 'S')
        {
            single[single_len].damage = d;
            single[single_len].cost = tmp;
            single_len++;
        }
        else
        {
            all[all_len].damage = d;
            all[all_len].cost = tmp;
            all_len++;
        }
    }//at least one of single_len and all_len is over 0
    for(index = 0; index < 100000; index++) single_cost[index] = 0;//initial single_cost
    min_single_cost(max_hp);//do the max and the rest is done
    printf("%lld", min_all_cost());
    return 0;
}
