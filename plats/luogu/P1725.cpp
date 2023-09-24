#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
int dp[N];
int n,l,r;
deque<int> q;

void solve(){
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++) cin>>a[i];
    memset(dp,128, sizeof(dp));
    dp[0] = 0;
    int ans = -INF;
    for(int i=l;i<=n;i++){
        // 只有当前i的左边返回q.front()在[i-r,i-l]中是
        while (!q.empty() && dp[i-l] >= dp[q.back()]) q.pop_back();
        q.push_back(i-l);

        if(!q.empty()){
            //i = 10 l= 2, r= 5 ,f = 4, [5, 8],
            while (!q.empty() && q.front() + r < i ) q.pop_front();
            if (!q.empty()) dp[i] = dp[q.front()] + a[i];
        }
        else {
            dp[i] = 0xffffffff;
        }

        if(i+r > n) ans = max(ans, dp[i]);
        
    }

    cout<<ans<<"\n";
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}