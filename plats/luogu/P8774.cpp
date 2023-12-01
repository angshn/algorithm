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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
ll ksm(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a) % mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
int p[N],q[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>q[i];
    }

    ll s1=1,s2=0,s3=0;
    for(int i=1;i<=n;i++){
        int pi = (1ll*p[i]*ksm(q[i],mod-2)%mod);
        int p1_i = (1ll*(q[i]-p[i])*ksm(q[i],mod-2)%mod);

        s3 = (s3 + s1)%mod;
        s2 = (s2 + 1ll*s1*pi)%mod;
        s1 = (s1 * p1_i)%mod;
    }

    cout<<1ll*s3*ksm(1-s2+mod,mod-2)%mod<<"\n";

    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}