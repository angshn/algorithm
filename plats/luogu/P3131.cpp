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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
ll a[N];
ll pre[N];
int Head[8],Tail[8];

void solve(){
    cin>>n;
    memset(Head,0x3f,sizeof(Head));
    memset(Tail,0,sizeof(Tail));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        pre[i] = (pre[i-1]+a[i])%7;
        if(Head[pre[i]]==INF) Head[pre[i]] = i;
        Tail[pre[i]] = i;
    }
    int ans = 0;
    Head[0]=0;
    for(int i=0;i<=6;i++){
        if(Tail[i]==0||Head[i]==INF)continue;
        int l,r;
        l = Head[i];
        r = Tail[i];
        ans = max(ans, r-l);
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