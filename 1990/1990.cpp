//现在给你一个长度为N的整数序列，序列的第i个表示编号为i的CD的初始好感度，这里保证第i张CD的初始好感度大于等于第i - 1张的初始好感度。接下来会给你M对整数x和y，表示在第i天编号x的CD好感度会增加y（y为1或 - 1），你需要求出在每次变化后二哥好感度最低的CD是哪张，如果有多张好感度都是最低的，那么选最后变成这个好感度的CD，在这里我们假设在初始序列中编号i的CD的变化到初始好感度的时间晚于编号i - 1的CD变化到其初始好感度的时间。
//
//输入格式
//输入共有两行。
//
//第1行两个整数N和M，表示CD数和需要询问的天数。
//
//第2行有n个整数，表示初始好感度。
//
//接下来M行，每行两个整数x, y，表示M次询问。
//
//输出格式
//对于每次询问输出这次变化后所求的CD编号。一个询问占一行。
//
//说明
//对于30%的数据：1≤n, m≤1001≤n, m≤100。 对于60%数据：1≤n, m≤100, 0001≤n, m≤100, 000。 对于全部数据：任何时刻好感度不会超过有符号32位整数，1≤n, m≤2, 000, 0001≤n, m≤2, 000, 000;


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;


int N, M;
int a, b;
int num[2000005];
int value[2000005];
int pos[2000005];

void swap(int& a, int& b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

void bubble(int ind, int type)
{
	value[ind] += type;
	switch (type)
	{
	case 1:
		while (ind < N && value[ind] > value[ind+1])
		{
			int tmpnum1 = num[ind];
			int tmpnum2 = num[ind + 1];
			swap(value[ind], value[ind + 1]);
			swap(num[ind], num[ind + 1]);
			swap(pos[tmpnum1], pos[tmpnum2]);
			ind++;
		}
		break;
	case -1:
		while (ind > 1 && value[ind] <= value[ind - 1])
		{
			int tmpnum1 = num[ind];
			int tmpnum2 = num[ind - 1];
			swap(num[ind], num[ind - 1]);
			swap(pos[tmpnum1], pos[tmpnum2]);
			if (value[ind] < value[ind-1])
			{
				swap(value[ind], value[ind - 1]);
			}
			ind--;
		}
		break;
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		num[i] = i;
		scanf("%d", &value[i]);
		pos[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &a, &b);

		bubble(pos[a],b);
		printf("%d\n", num[1]);
		/*for (int j = 1; j <= N; j++)
		{
			cout <<"num:"<<j<<":at"<< pos[j]<<"="<<value[pos[j]]<<" ";
		}
		cout << endl;*/
	}
	system("pause");
}
