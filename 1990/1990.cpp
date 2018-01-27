//���ڸ���һ������ΪN���������У����еĵ�i����ʾ���Ϊi��CD�ĳ�ʼ�øжȣ����ﱣ֤��i��CD�ĳ�ʼ�øжȴ��ڵ��ڵ�i - 1�ŵĳ�ʼ�øжȡ������������M������x��y����ʾ�ڵ�i����x��CD�øжȻ�����y��yΪ1�� - 1��������Ҫ�����ÿ�α仯�����øж���͵�CD�����ţ�����ж��źøжȶ�����͵ģ���ôѡ���������øжȵ�CD�����������Ǽ����ڳ�ʼ�����б��i��CD�ı仯����ʼ�øжȵ�ʱ�����ڱ��i - 1��CD�仯�����ʼ�øжȵ�ʱ�䡣
//
//�����ʽ
//���빲�����С�
//
//��1����������N��M����ʾCD������Ҫѯ�ʵ�������
//
//��2����n����������ʾ��ʼ�øжȡ�
//
//������M�У�ÿ����������x, y����ʾM��ѯ�ʡ�
//
//�����ʽ
//����ÿ��ѯ�������α仯�������CD��š�һ��ѯ��ռһ�С�
//
//˵��
//����30%�����ݣ�1��n, m��1001��n, m��100�� ����60%���ݣ�1��n, m��100, 0001��n, m��100, 000�� ����ȫ�����ݣ��κ�ʱ�̺øжȲ��ᳬ���з���32λ������1��n, m��2, 000, 0001��n, m��2, 000, 000;


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
