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
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
ll a[N], s[N];
ll dp[N];
ll n, d, k;

int check(int g)
{
    // 维护一个最大单调队列
    deque<ll> q;
    int cur = 0;
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        // 如果cur当前的位置能跳到i
        for(;cur<i && a[i]-a[cur]>=max(d-g,1LL);cur++){
            if(q.empty())
            {
                q.push_back(cur);
            }
            else
            {
                while (!q.empty() && dp[cur] >= dp[q.back()])
                    q.pop_back();
                q.push_back(cur);
            }
        }
        // 去除那些超出窗口范围的点
        while(!q.empty() && a[i] - a[q.front()] > d+g){//从q.front()这个点到i点的距离已经超出了当前情况下的最大范围
            q.pop_front();
        }
        if(!q.empty()){
            dp[i] = dp[q.front()] + s[i];
        }
        else {
            dp[i] = -999999999999;
        }
        if(dp[i]>=k){
            return 1;
        }
    }
    return 0;
}
void solve()
{
    
    cin >> n >> d >> k;
    ll score;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> s[i];
    }
    int l = 0, r = a[n], ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool valid = check(mid);
        if (valid)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout<<ans<<endl;
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