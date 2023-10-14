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
int fa[N],head[N],cnt,head_query[N],cnt_query,ans[N];
int vis[N];
struct {int to,next,num;} edge[2*N],query[N<<1];
void init(){
    for(int i=0;i<2*N;i++){
        edge[i].next=head[i]=query[i].next=head_query[i]=-1;
    }
    cnt=0;cnt_query=0;
}

void addedge(int u,int v){
    ++cnt;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

void add_query(int x,int y,int num){
    cnt_query++;
    query[cnt_query].to=y;
    query[cnt_query].num=num;
    query[cnt_query].next=head_query[x];
    head_query[x]=cnt_query;
}

int find_set(int x){
    return fa[x]==x?fa[x]:fa[x]=find_set(fa[x]);
}

void tarjan(int x){
    vis[x]=true;
    for(int i=head[x];~i;i=edge[i].next){
        int y=edge[i].to;
        if(!vis[y]){
            tarjan(y);fa[y]=x;//后缀遍历，子节点遍历结束后才到父节点，因此lca不会被影响
        }
    }
    for(int i=head_query[x];~i;i=query[i].next){//回溯回来要考察相关的所有点对
        int y=query[i].to;
        if(vis[y]){//如果同一个子树下有遍历过的点，那么就更新答案
            ans[query[i].num] = find_set(y);
        }
    }
}

void solve(){
    init();
    memset(vis,0,sizeof(vis));
    int n,m,root;cin>>n>>m>>root;
    for(int i=1;i<n;i++){
        fa[i]=i;
        int u,v;cin>>u>>v;
        addedge(u,v);addedge(v,u);
    }
    fa[n]=n;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        add_query(a,b,i);add_query(b,a,i);
    }
    tarjan(root);
    for(int i=1;i<=m;++i) {
        cout<<ans[i]<<"\n";
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