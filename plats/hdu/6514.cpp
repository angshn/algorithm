#include <bits/stdc++.h>
#define ll long long int
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
#define FASTIO                \
	ios ::sync_with_stdio(0); \
	cin.tie(0);               \
	cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
void solve()
{
	while (cin >> n >> m)
	{
		vector<vector<int>> a(n + 5, vector<int>(m + 5));
		vector<vector<int>> b(n + 5, vector<int>(m + 5));

		int p;
		cin >> p;
		int x1, y1, x2, y2;
		for (int i = 1; i <= p; i++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			a[x1][y1]++;
			a[x1][y2 + 1]--;
			a[x2 + 1][y1]--;
			a[x2 + 1][y2 + 1]++;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a[i][j] > 0 ? 1 : 0);
			}
		}

		int q;
		cin >> q;

		for (int j = 1; j <= q; j++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			int area = (x2 - x1 + 1) * (y2 - y1 + 1);
			if (b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1] == area)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\devel\\algorithm\\in.txt", "r", stdin);
#endif
	FASTIO
	solve();
	return 0;
}