#include<iostream>
using namespace std;
 
int main()
{
	//long long  **color, *num, *len_color, i, j, k, m, n, odd, even, tmp, result = 0;
	 long long  **color, *num, *p, *fanren,*len_color, i, j, k, m, n, tmp, result = 0;
	cin >> n >> m;
 
 
	len_color = new long long[m + 1];
	for (i = 0; i <= m; ++i)
		len_color[i] = 0;
	num = new long long [n+1];
	for (i = 1; i <= n; ++i)
		cin >> num[i];
	p = new long long[n + 1];
	for (i = 1; i <= n; ++i)
		cin >> p[i];
	for (i = 1; i <= n; ++i)
	{
		len_color[p[i]]++;
	}
	fanren = new long long[m + 1];
	for (i = 0; i <= m; ++i)
		fanren[i] = 0;
 
	color = new long long  *[m + 1];
	for (i = 0; i <= m; ++i)
		color[i] = new long long [len_color[i]];   //  all <=20???
	for (i = 1; i <= n; ++i)
	{
		tmp = p[i];
		color[p[i]][fanren[tmp]] = i;
		fanren[tmp]++;
	}
 
 
	/*for (i = 1; i <= m; ++i)
	{
		for (j = 0; j <len_color[i]; ++j)
			cout << color[i][j] << " ";
		cout << " ******* " << len_color[i] << endl;
	}*/
 
	/*for (i = 1; i <= m; ++i)
	{//color[i]的长度为   [0 , len_color[i] ] 但是最大区间不超过20
		for (j = 0; j <len_color[i]; ++j)
		{
			for (k = j + 1; k < len_color[i]; ++k)   //keyi youhua 
			{
				if (color[i][j] % 2 != color[i][k] % 2)
					continue;
				result += (color[i][j] + color[i][k])* (num[color[i][j]] + num[color[i][k]]);
				result %= 10007;
			}
		}
 
	}*/
 
	long long  len_odd = 0, len_even = 0, odd_sum = 0, even_sum = 0;
 
	for (i = 1; i <= m; ++i)
	{
		len_odd = 0; len_even = 0; odd_sum = 0; even_sum = 0;
 
		for (j = 0; j < len_color[i]; ++j)
		{
			if (color[i][j] % 2 == 0)
			{
				len_even++;
				even_sum += num[color[i][j]];
				even_sum %= 10007;
			}
			else
			{
				odd_sum += num[color[i][j]];
				odd_sum %= 10007;
			}
		}
		len_odd = len_color[i] - len_even;
 
		//
 
		//判断奇数的
		for (j = 0; j < len_color[i]; ++j)
		{
			if (color[i][j] % 2 != 0)
			{
				result = (result % 10007) + ((len_odd - 2)* (num[color[i][j]] % 10007) + odd_sum) * color[i][j];
				//result = result + (len_odd - 2)*(color[i][j] * (num[color[i][j]] % 10007)) + (odd_sum - num[color[i][j]])*color[i][j];
				result %= 10007;
			}
			else
			{
				result = result + (len_even - 2)*color[i][j] * (num[color[i][j]] % 10007) + even_sum*color[i][j];
				result %= 10007;
			}
		}
	}
 
	while (result < 0)
	{
		result += 10007;
	}
 
	cout << result%10007 << endl;
 
	return 0;
 
}
