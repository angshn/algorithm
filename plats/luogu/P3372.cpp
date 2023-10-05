#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
ll tree1[N], tree2[N];
#define lowbit(x) (x&(-x))
void update1(ll x,ll v){ while(x<=N){ tree1[x]+=v; x+=lowbit(x); } }
void update2(ll x,ll v){ while(x<=N){ tree2[x]+=v; x+=lowbit(x); } }

ll sum1(int x){ ll ans = 0; while(x>0){ ans+=tree1[x]; x-=lowbit(x); } return ans; }
ll sum2(int x){ ll ans = 0; while(x>0){ ans+=tree2[x]; x-=lowbit(x); } return ans; }

int n,m;


void solve(){
    cin>>n>>m;
    ll old = 0;
    for(int i=1;i<=n;i++){
        ll a;cin>>a;
        update1(i,a-old);
        update2(i,(i-1)*(a-old));old = a;
    }
    while(m--){
        int o,x,y,k;cin>>o;
        if(o==1){
            cin>>x>>y>>k;
            update1(x,k);
            update1(y+1,-k);
            update2(x,(x-1)*k);
            update2(y+1,-k*y);
        }
        else {
            cin>>x>>y;
            ll ans = y*sum1(y)-(x-1)*sum1(x-1)-sum2(y)+sum2(x-1);
            cout<<ans<<endl;
        }
    }
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