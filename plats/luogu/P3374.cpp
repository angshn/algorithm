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
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
ll tree[N];
int lowbit(int x){return x&(-x);}
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}

ll sum(int x){
    ll ans = 0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;update(i,x);
    }
    while(m--){
        ll o,l,r;cin>>o>>l>>r;
        if(o==1){
            update(l,r);
        }
        else {
            cout<<sum(r)-sum(l-1)<<endl;
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