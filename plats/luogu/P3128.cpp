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
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
struct {
    int to,next;
}edge[2*N];
int head[2*N],D[N],deep[N],fa[N][20],ans,cnt;

void addedge(int u,int v){
    ++cnt;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;

}
void dfs1(int x,int f)
{
    deep[x]=deep[f]+1;
    fa[x][0]=f;
    for(int i=1;(1<<i)<=deep[x];i++)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(int i=head[x];i;i=edge[i].next)
    {
        if(edge[i].to!=f)
        {
            dfs1(edge[i].to,x);
        }
    }
}
int LCA(int u,int v)
{
    if(deep[u]<deep[v]) swap(u,v);

    for(int i=19;i>=0;i--)
    {
        if(deep[u]-(1<<i)>=deep[v])
        {
            u=fa[u][i];
        }
    }
    if(u==v) return u;

    for(int i=19;i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }

    }
    return fa[u][0];
}

void dfs2(int u,int f){//使用深搜来计算每个节点的和，所有子节点到父节点都做前缀累加
    for(int i=head[u];i;i=edge[i].next)
    {
        int e=edge[i].to;
        if(e==f) continue;
        dfs2(e,u);
        D[u]+=D[e];
    }
    ans=max(ans,D[u]);
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        addedge(u,v);addedge(v,u);
    }
    dfs1(1,0);
    for(int i=1;i<=m;++i)
    {
        int u,v;cin>>u>>v;

        int lca=LCA(u,v);
        D[u]++;D[v]++;D[lca]--;D[fa[lca][0]]--;
        
    }

    dfs2(1,0);
    cout<<ans<<endl;
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
