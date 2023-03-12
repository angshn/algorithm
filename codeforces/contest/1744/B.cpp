#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define INPUT_PATH "/Users/syang/dev/algorithm/in.in"
#define ll long long int
using namespace std;
const int N = 1e5 + 5;
int odd, even;

inline const int query(int type, int x)
{
    ll s = 0;
    if (type == 0)
    {
        s += even * x;
        if (x % 2)
        {
            //偶数加奇数等于奇数
            odd += even;
            even = 0;
        }
    }
    else
    {
        s += odd * x;
        if (x % 2)
        {
            even += odd;
            odd = 0;
        }
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
#endif
    int t;
    int n, q;
    cin >> t;
    // scanf("%d", &t);
    while (t--)
    {
        cin >> n >> q;
        // scanf("%d %d", &n, &q);

        int type;
        int x;
        ll sum = 0;
        odd = even = 0;
        while (n--)
        {
            cin >> x;
            // scanf("%d", &x);
            x % 2 ? odd++ : even++;
            sum += x;
        }
        while (q--)
        {
            // scanf("%d %d", &type, &x);
            cin >> type >> x;
            sum += query(type, x);
            cout << sum << '\n';
            // printf("%lld\n", sum);
        }
    }
    return 0;
}