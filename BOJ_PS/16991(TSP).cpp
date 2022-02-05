//소수점 이하 n자리 고정은 cout<<fixed;cout.precision(n);
//중요! memset으로 double 테이블 초기화하면 nan이 들어간다. double 테이블은 루프로 직접 초기화하자
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<double, double>> pt;
double adjmat[16][16];
double dp[66000][16];
int n, allvisit;
int pow(int n)
{
	int i = n, mul = 1;
	while (i--)
		mul *= 2;
	return mul;
}
double calc_dist(int i, int j)
{
	return sqrt((pt[j].first - pt[i].first) * (pt[j].first - pt[i].first) + (pt[j].second - pt[i].second) * (pt[j].second - pt[i].second));
}
double func(int visit, int now)
{
	double minval = 1e9;
	if (dp[visit][now] != 0.0)
	{
		return dp[visit][now];
	}
	if (visit == allvisit)
		return adjmat[now][0];
	for (int i = 1; i < n; i++)
	{

		if (!((visit >> i) & 1) && adjmat[now][i])
		{
			double tmp = adjmat[now][i] + func(visit | 1 << i, i);
			minval = min(minval, tmp);
		}
	}
	dp[visit][now] = minval;
	return minval;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	double x, y;
	cin >> n;
	allvisit = pow(n) - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pt.push_back({x, y});
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				adjmat[i][j] = 0;
			else
				adjmat[i][j] = calc_dist(i, j);
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << func(1, 0);
	return 0;
}
