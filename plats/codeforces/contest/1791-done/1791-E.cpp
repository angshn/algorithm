#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#define INPUT_PATH "in.in"
#define TCASE \
    int tc;   \
    cin >> tc;
#define ll long long int
using namespace std;
const int N = 2e5 + 5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    TCASE
    while (tc--)
    {
        int n;
        cin >> n;
        int negs = 0;

        ll sum = 0;
        int fir = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x <= 0)
                negs++;
            sum += abs(x);
            if (fir > abs(x))
                fir = abs(x);
        }
        ll res;
        if (negs & 1)
        {
            res = sum - fir * 2;
        }
        else
        {
            res = sum;
        }
        cout << res << '\n';
    }
}