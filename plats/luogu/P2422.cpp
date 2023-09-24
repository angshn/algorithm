#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf, size)            \
    for (int i = 0; i < size; i++) \
        cin >> buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
ll prefix[N];
ll q[N], range[N];
int tail;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    ll ans = -1e8;
    for (int i = 1; i <= n+1; i++)
    {

        while (a[q[tail]] > a[i])
        {
            // 当前需要弹出比他大的数
            range[q[tail]] += prefix[i - 1] - prefix[q[tail]];
            tail--;
        }
        range[i] = prefix[i] - prefix[q[tail]];
        q[++tail] = i;
    }

    for(int i=1;i<=n;i++) ans = max(ans, range[i]*a[i]);
    cout << ans << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algo/in.in", "r", stdin);
#endif
    FASTIO
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}