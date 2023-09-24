#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];
void solve()
{
    int n;
    cin >> n;
    vector<ll> sum(n + 1);
    vector<ll> cnt(n + 1);
    vector<ll> add(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum[i + 1] = sum[i] + b[i];
    }
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(sum.begin() + 1, sum.end(), a[i] + sum[i]) - sum.begin() - 1;
        cnt[i] += 1;
        cnt[j] -= 1;
        add[j] += a[i] + sum[i] - sum[j];
    }
    for (int i = 0; i < n; i++)
    {
        cout << cnt[i] * b[i] + add[i] << " ";
        cnt[i + 1] += cnt[i];
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}