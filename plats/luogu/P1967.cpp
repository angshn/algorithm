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
struct {
    int to,next;
    int w;
}edge[N<<1];
int fa[N][20],deep[N];
int head[N<<1];
int cnt;
int payload[N][20];//倍增记录每个节点到上方位置的最小边权
int vis[N];
void addedge(int u,int v,int w){
    ++cnt;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].w=w;
    head[u]=cnt;
}
void dfs(int u,int f,int c)
{
    vis[u] = 1;
    deep[u]=deep[f]+1;
    fa[u][0]=f;
    payload[u][0]=c;//当前节点到父节点的最小值为c,是初始化条件
    for (int i = 1; (1 << i) <= deep[u]; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        payload[u][i] = min(payload[u][i - 1], payload[fa[u][i - 1]][i - 1]); // 跳一半和再跳一半的最小值
    }

    for(int i=head[u];i;i=edge[i].next){//死循环了
        if(edge[i].to!=f && !vis[edge[i].to]){
            dfs(edge[i].to,u,edge[i].w);
        }
    }
    vis[u]=0;
}

int LCA(int u,int v)
{
    if(u<v) swap(u,v);
    for(int i=19;i>=0;i--){
        if(deep[u]-(1<<i)>=deep[v]){
            u=fa[u][i];
        }
    }
    if(u==v) return u;

    for(int i=19;i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];v=fa[v][i];
        }
    }
    return min(payload[fa[u][0]][0],payload[fa[v][0]][0]);

}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        
        addedge(u,v,w);addedge(v,u,w);
    }

    dfs(1,0,INF);
    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        cout<<LCA(x,y)<<"\n";

    }
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
