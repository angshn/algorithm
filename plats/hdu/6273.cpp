#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
ll d2[N],d3[N];
int n,m;
const int MOD = 998244353;
ll fastpow(ll a,ll x){
    ll ans = 1;
    while(x){
        if(x&1) ans=ans*a%MOD;
        a=a*a%MOD;
        x>>=1;
    }
    return ans;
}

void solve(){
    memset(d2,0,sizeof(d2));
    memset(d3,0,sizeof(d3));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int l,r,x;cin>>l>>r>>x;
        if(x==2){
            d2[l]++;d2[r+1]--;
        }
        else {
            d3[l]++,d3[r+1]--;
        }
    }
    ll m2=d2[1],m3=d3[1];
    for(int i=1;i<=n;i++){
        d2[i]=d2[i-1]+d2[i];
        d3[i]=d3[i-1]+d3[i];
        m2 = min(d2[i],m2);
        m3 = min(d3[i],m3);
    }
    ll ans = (fastpow(2,m2)*fastpow(3,m3))%MOD;
    cout<<ans<<'\n';
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}