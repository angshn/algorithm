#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define GETA(buf, size)            \
    for (int i = 0; i < size; i++) \
        cin >> buf[i];
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
int cache[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    GETA(a, n);
    int l = 0;
    int sum = 0;
    int sum_dis = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++)
    {
        cache[a[r]]++;
        if (cache[a[r]] == 1)
        {
            sum_dis++;
        }
        while (sum_dis > k && cache[a[l]])
        {
            // 从l开始删除
            cache[a[l]]--;
            if (cache[a[l]] == 0)
            {
                sum_dis--;
            }
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/codeforces/in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}