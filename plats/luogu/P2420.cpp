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

struct {
    int to,next,w;
}edge[N<<1];
int cnt;
int head[N<<1];
int val[N][22];
void addedge(int u,int v,int w){
    ++cnt;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].w=w;
    head[u]=cnt;
}
int fa[N][22];//最近公共祖先
int deep[N];
int d[N];
//向上跳的过程中将累计异或
void dfs(int u,int f,int w){
    deep[u]=deep[f]+1;
    fa[u][0]=f;
    val[u][0]=w;//当前节点到父节点的权值
    for(int i=1;(1<<i)<=deep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
        //向上跳2^i个父亲时，先跳一半，再从一半异或另一半
        val[u][i] = val[u][i-1]^val[fa[u][i-1]][i-1];
    }
    for(int i=head[u];i;i=edge[i].next){
        if(edge[i].to!=f){
            dfs(edge[i].to,u,edge[i].w);
        }
    }
}

int LCA(int u,int v){
    if(deep[u]<deep[v]) swap(u,v);
    int ans=0;
    for(int i=19;i>=0;i--){
        //从u开始往上跳2^i次方，如果跳过了就i-1，
        //没有跳过就更新当前跳到的节点
        if(deep[u]-(1<<i)>=deep[v]) {
            ans^=val[u][i];//记录过程中的异或值
            u=fa[u][i];
        }
    }
    //如果v就是u的父亲，那么他们之间的异或值就是ans
    if(u==v) return ans;
    //否则就要计算v也往上跳的异或值
    int ans2=0;
    for(int i=19;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){//父亲不等时
            ans^=val[u][i];ans2^=val[v][i];//记录异或值
            u=fa[u][i];v=fa[v][i];//更新父节点
        }
    }

    return ans^ans2^val[u][0]^val[v][0];



}

void solve(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;cin>>u>>v>>w;
        d[u]+=2;d[v]+=2;
        addedge(u,v,w);addedge(v,u,w);
    }
    int root=0;
    for(int i=1;i<n;i++){
        if(d[i]==2){
            root=i;
            break;
        }
    }
    dfs(root,0,0);
    int m;cin>>m;
    while(m--){
        int u,v;cin>>u>>v;
        cout<<LCA(u,v)<<"\n";
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