#include <stdio.h>
using namespace std;

struct Node
{
    int weight;
    int volumn;
};
int input_num;
int widget_num = 0;
int bag_volumn;
int v[2][1001];
Node data[10001];
int main(void)
{
    int index, index2, index3, tmp1, tmp2, tmp3, stp;
    scanf("%d %d", &input_num, &bag_volumn);
    for(index = 0; index < input_num; index++)
    {
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        stp = 1;
        while(tmp1 - stp >= 0)
        {
            data[widget_num].volumn = stp * tmp2;
            data[widget_num].weight = stp * tmp3;
            widget_num++;
            tmp1 -= stp;
            stp *= 2;
        }
        data[widget_num].volumn = tmp1 * tmp2;
        data[widget_num].weight = tmp1 * tmp3;
        widget_num++;
    }
    int counts = 0;
    for(index = 0; index < widget_num; index++)
    {
        for(index3 = 0; index3 <= bag_volumn; index3++)
        {
            if(counts == 0)
            {
                if(index3 - data[index].volumn < 0) v[counts][index3] = 0;
                else v[counts][index3] = data[index].weight;
            }
            else
            {
                if(index3 - data[index].volumn < 0) v[counts%2][index3] = v[(counts+1)%2][index3];
                else v[counts%2][index3] = (v[(counts+1)%2][index3-data[index].volumn] + data[index].weight) > v[(counts+1)%2][index3] ?
                                                             v[(counts+1)%2][index3-data[index].volumn] + data[index].weight  :  v[(counts+1)%2][index3];
            }
        }
        counts++;
    }
    printf("%d", v[(counts+1)%2][bag_volumn]);
    return 0;
}
