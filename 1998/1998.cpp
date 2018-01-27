#include <iostream>
#include <cmath>

using namespace std;

void quickSort(int *, int, int);

int main()
{
    long range;
    int *locate;
    int index;
    cin >> range;
    locate = new int[range];
    for(index = 0; index < range; index++)
    {
        cin >> locate[index];
    }
    quickSort(locate, 0, range - 1);
    int sum = 0;
    int key = locate[range/2];
    for(index = 0; index < range; index++)
    {
        sum += (key - locate[index]) > 0 ? (key - locate[index]) : -(key - locate[index]);
    }
    cout << sum;
    return 0;
}
void quickSort(int *locate, int down, int up)
{
    if(down >= up) return ;
    int tmp;
    int i, j;
    int index;
    int pivot = locate[down];
    for(i = down + 1; i <= up; i++)
    {
        if(locate[i] < pivot) continue;
        else break;
    }
    for(j = i + 1; j <= up; j++)
    {
        if(locate[j] < pivot)
        {
            tmp = locate[j];
            locate[j] = locate[i];
            locate[i++] = tmp;
        }
    }
    locate[down] = locate[i - 1];
    locate[i - 1] = pivot;
    quickSort(locate, down, i - 2);
    quickSort(locate, i, up);
}
