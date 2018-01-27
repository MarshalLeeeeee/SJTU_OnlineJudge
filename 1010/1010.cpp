#include <iostream>
#include <cstdio>
using namespace std;
int curr = 0, save = 0;
int flag = 1;

int main()
{
    int spend;
    for(int index = 1; index <= 12; index++)
        scanf("%d", &spend);
        curr += 300;
        if(curr - spend < 0) {flag = 0; printf("-%d", index); break;}
        else
        {
            int more = curr - spend;
            save += more/100 * 100;
            curr = more - more/100 * 100;
        }
    }
    if(flag) printf("%d", (6 * save / 5) + curr);
    return 0;
}
