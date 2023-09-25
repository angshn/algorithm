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
int n,m;
ll s;
int w[N],v[N];
ll pre[N];
int num[N];
int l[N],r[N];
ll ans;
ll sum = 0;

bool check(int mid){
    memset(pre,0,sizeof(pre));
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++){
        if(w[i]>=mid){
            pre[i]=pre[i-1]+v[i];
            num[i] = num[i-1]+1;
        }
        else {
            pre[i] = pre[i-1];
            num[i] = num[i-1];
        }
    }
    sum = 0;
    ll y = 0;
    for(int i=1;i<=m;i++){
        int _l = l[i]-1;
        int _r = r[i];
        ll y_i = (num[_r]-num[_l])*(pre[_r]-pre[_l]);
        y+=y_i;
    }
    sum = abs(y-s);
    return y>s;

}

void solve(){
    cin>>n>>m>>s;
    int maxr = 0;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        maxr = max(w[i],maxr);
    }
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    int l = 0, r = maxr;
    ll ans = 0x3fffffffffffffff;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }
        else {
            r= mid-1;
        }
        ans = min(ans, sum);
    }
    cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}