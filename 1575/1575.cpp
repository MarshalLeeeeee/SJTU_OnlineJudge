#include <iostream>
#include <fstream>

using namespace std;

int exam_dist(long long *, long, long long, long);

int main()
{
    long long L, left, right;
    long N, M, index;
    cin >> L >> N >> M;
    long long *distance;
    distance = new long long[N + 2];
    distance[0] = 0;
    for(index = 1; index < N + 1; index++)
    {
        cin >> distance[index];
    }
    distance[index] = L;
    if(N == 0 || N == M) cout << L;
    else
    {
        left = 1; right = L + 1;
        while(left + 1 < right)
        {
            //cout << left << ' ' << right << endl;
            if(exam_dist(distance, N + 2, (left + right) / 2, M)) left = (left + right) / 2;
            else right = (left + right) / 2;
        }
        cout << left;
    }
    return 0;
}
int exam_dist(long long *distance, long N, long long dist, long M)
{
    int flag = 0;
    long index, sum = 0, pre_index = 0;
    for(index = 1; index < N; index++)
    {
        if(distance[index] - distance[pre_index] < dist) sum++;
        else pre_index = index;
    }
    return sum <= M;
    //if sum < M, it means the dist is too small
}
