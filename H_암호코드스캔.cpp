// H_암호코드스캔.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"



#define _CRT_SECURE_NO_WARNNINGS

#define N_MAX 2000
#define M_MAX 500

#define CLEN_MAX	8


char data[N_MAX + 1][M_MAX + 1];
int N, M;

int FindCode(int x, int y);
int	IncludeCode(char *d, int y);
void  GetCodeValue(int *c, char *d);
int CnvCode(char *d);
int CheckCode(int *c);


int main()
{
	int test_case;
	int T;
	int i, res;



	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//memset(data, NULL, N_MAX* M_MAX);

		scanf("%d %d", &N, &M);

		for (i = 0; i < N; i++)
		{

			scanf("%s", &data[i][0]);

		}

		res = FindCode(N, M);
		printf("#%d %d\n", test_case, res);
	}


	return 0;
}


int FindCode(int Ymax, int Xmax)
{
	int		y;
	int		code[CLEN_MAX];
	int		start_p;

	for (y = 0; y<Ymax; y = y + 5)
	{
		start_p = IncludeCode(data[y], Xmax);

		if (start_p < M_MAX + 1)
		{
			GetCodeValue(code, &data[y][start_p]);
			return CheckCode(code);
		}
	}

}

int	IncludeCode(char *d, int Xmax)
{
	int x;
	for (x = Xmax - 1; x >= 0; x--)
	{
		if (d[x] != '0')
			return x - 56 + 1;
	}
	return (M_MAX + 1);


}


void GetCodeValue(int *c, char *d)
{
	int i;

	for (i = 0; i < CLEN_MAX; i++)
	{
		c[i] = CnvCode(&d[i * 7]);
	}

}


int CnvCode(char *d)
{
	if ((d[1] == '0') & (d[2] == '0'))
	{
		if (d[4] == '0') return 9;
		else             return 0;
	}
	else if ((d[1] == '0') & (d[2] == '1'))
	{
		if (d[3] == '1') return 1;
		else             return 2;
	}
	else if ((d[1] == '1') & (d[2] == '1') & (d[3] == '1'))
	{
		if (d[4] == '1') return 3;
		else             return 7;
	}

	else if ((d[1] == '1') & (d[2] == '0'))
	{
		if (d[4] == '1') return 6;
		else             return 4;
	}
	else if ((d[1] == '1') & (d[2] == '1') & (d[3] == '0'))
	{
		if (d[4] == '1') return 8;
		else             return 5;
	}
	return -1;

}

int CheckCode(int *c)
{
	int t = (c[0] + c[2] + c[4] + c[6]) * 3 + (c[1] + c[3] + c[5]) + c[7];

	int d = t / 10;
	if (t == d * 10)
		return (c[0] + c[2] + c[4] + c[6] + c[1] + c[3] + c[5] + c[7]);
	return 0;

}