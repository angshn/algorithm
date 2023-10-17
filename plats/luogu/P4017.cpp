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
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
struct Edge{
    int to,next;
}edge[N*100];
int head[N],cnt,d[N];
int n,m;
const int MOD = 80112002;
void addedge(int u,int v){
    ++cnt;edge[cnt].to=v;edge[cnt].next= head[u];head[u]=cnt;
}
ll mem[N];
ll dfs(int u){

    if(head[u]==0){
        return 1;
    }
    if(mem[u]!=-1){
        return mem[u];
    }
    ll ans = 0;
    for(int i=head[u];i;i=edge[i].next){
        int to = edge[i].to;
        ans=(ans+dfs(to))%MOD;
    }
    mem[u] = ans % MOD;
    return mem[u];
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        addedge(u,v);
        d[v]++;
    }
    for(int i=0;i<N;i++) mem[i] = -1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            ans = (ans +dfs(i))%MOD;
        }
    }
    cout<<ans<<"\n";
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