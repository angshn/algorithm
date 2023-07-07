#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define INPUT_PATH "in.in"
#define TCASE  \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define ll long long int
using namespace std;
const int N = 2e5 + 5;
int pre[N];
static inline int sum_digits(int x)
{
    int res = 0;
    for (int i = 0; x; i++)
    {
        res += (x % 10);
        x /= 10;
    }
    return res;
}
enum Type
{
    UPDATE = 1,
    QUERY
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    TCASE
    {
        int n, q;
        cin >> n >> q;
        set<int> s;
        for (int i = 1; i <= n; i++)
        {
            cin >> pre[i];
            if(pre[i]>9) s.insert(i);
        }
        for (int i = 0; i < q; i++)
        {
            int d, l, r;
            cin >> d;
            if (d == UPDATE)
            {
                cin >> l >> r;
                // update
                int pos = l;
                while (!s.empty())
                {
                    auto it = s.lower_bound(pos);
                    if(it == s.end() || *it > r) break;
                    pre[*it] = sum_digits(pre[*it]);
                    int idx = *it;
                    s.erase(it);
                    if(pre[idx]>9) s.insert(idx);
                    pos = idx+1;
                }
                
            }
            else if (d == QUERY)
            {
                cin >> l;
                // quering tree
                cout<<pre[l]<<"\n";
            }
        }
    }
}