#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define GETA(buf, size)            \
    for (int i = 0; i < size; i++) \
        cin >> buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
ll a[N];
void solve()
{
    int n;
    ll p;
    cin >> n >> p;
    ll sumA = 0;
    ll ans = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sumA += a[i];
    }
    if (sumA < p)
    {
        ans = p / sumA * n;
        p = p % sumA;
    }
    ll sum = 0;
    ll mx = INF;
    int l = 0;
    int stat = 0;
    rep(r, 0, n << 1)
    {
        sum += a[r % n];
        while (sum - a[l % n] >= p)
        {   sum -= a[l % n];
            l++;
        }
        if (sum >= p && mx > r - l + 1)
        {
            mx = r - l + 1;
            stat = l;
        }
    }

    /*     if (all)
        {
            // cout<<start+1<<" "<<sum<<endl;
            cout << "prefix sum = " << sum << endl;
            cout << "cnt = " << p / sum << endl;
            cout << "remain = " << p % sum << endl;
            ll remain = p % sum;
            ll _s = 0;
            ans = p / sum * n;

            rep(i, 0, n)
            {
                _s += a[i];
                if (_s >= remain)
                {
                    ans += i + 1;
                    break;
                }
            }
        } */
    cout << (stat % n) + 1 << " " << ans + (mx == INF ? 0 : mx) << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/codeforces/in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    // cout<<1000000000000000000/28<<endl;
    return 0;
}