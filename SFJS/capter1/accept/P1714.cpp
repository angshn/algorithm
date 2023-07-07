#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
ll pre[N];
deque<int> q;
void solve(){
    int n,m;cin >> n >> m;
    pre[0] = 0;
    rep(i,1,n+1) {
        ll x;cin>>x; pre[i]=pre[i-1]+x;
    }
    ll ans = -INF;
    q.push_back(0);
    rep(i,1,n+1){
       
        while(!q.empty() && pre[q.back()] > pre[i]) q.pop_back();
        q.push_back(i);
        ans = max(pre[i] - pre[q.front()] , ans);
        if(i>=m){
            while(!q.empty() && q.front() <= i - m) q.pop_front();
        }
    }
    cout<<ans<<endl;
    

}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.in","r",stdin);
#endif
    FASTIO
#ifndef NO_MULTICASE
    int t=1;
    while(t--) 
#endif
    solve();
    return 0;
}