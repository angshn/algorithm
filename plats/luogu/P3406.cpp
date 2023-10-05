#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read();
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
ll p[N];
ll D[N];
ll pre[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=2;i<=m;i++){
        int l = min(p[i],p[i-1]);
        int r = max(p[i],p[i-1]);
        D[l]++;
        D[r]--;
    }
    for(int i=1;i<=n-1;i++){
        D[i] = D[i-1]+D[i];
    }

    ll ans = 0;
    ll a,b,c;
    ll R;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b>>c;
        if(D[i]*a < c+b*D[i]){
            R = a;
        }
        else {
            ans+=c;
            R = b;
        }
        pre[i] = pre[i-1]+R;
    }

    for(int i=2;i<=m;i++){
        int l = min(p[i],p[i-1]);
        int r = max(p[i],p[i-1]);
        ans += pre[r-1]-pre[l-1];
    }
    cout<<ans<<endl;
}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
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