#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <array>
#define INPUT_PATH "in.in"
#define ll long long int
using namespace std;
const int N = 1e5 + 5;
#define fst first
#define sd second
#define pb push_back
#define all(x) x.begin(), x.end()
static inline void solve()
{
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> buf;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        buf.pb({x + min(i + 1, n - i), x + i + 1});
    }
    sort(all(buf));
    vector<ll> sum_pre(n + 1);
    sum_pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum_pre[i] = buf[i - 1].fst + sum_pre[i - 1];
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ll tc = c - buf[i].sd;
        int l = 0, r = n;
        ll _max = -0x3f3f3f3f;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            ll p = sum_pre[mid];
            ll pos = mid + 1;
            if (mid > i)
            {
                p -= buf[i].fst;
                pos = mid;
            }

            if (tc >= p)
            {
                _max = max(_max, pos);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cnt = max(_max, cnt);
    }
    cout << cnt << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}