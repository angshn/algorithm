#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf, size)            \
	for (int i = 0; i < size; i++) \
		cin >> buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
class a
{
public:
	virtual void func1();
	void func2();
	static void func3();
	static int i;

private:
	int j;
	char c;
};
void solve()
{
int num[5]={1,2,3,4,5};
cout<<*((int*)(&num+1)-1);
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