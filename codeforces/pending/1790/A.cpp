#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf, size)            \
    for (int i = 0; i < size; i++) \
        cin >> buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const string PI = "314159265358979323846264338327950288419716939937510";

void solve()
{
    string s;
    cin >> s;
    int len = s.length();
    int l = 0;
    if(s[0] != PI[0]) {
        cout << 0 << endl;
        return ;
    }
    else {
        rep(i, 0, len)
        {
            if (s[i] != PI[i])
            {
                break;
            }
            l = i+1;
        }
    }

    cout<<l<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/root/devel/algorithm/in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}