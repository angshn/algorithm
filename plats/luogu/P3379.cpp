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
}edge[N<<1];
int head[N<<1],cnt;

void addedge(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next = head[u];
    head[u]=cnt;
}

int fa[N][22],deep[N];

void dfs(int p,int f){
    deep[p]=deep[f]+1;
    fa[p][0]=f;
    for(int i=1;(1<<i)<=deep[p];i++){
        fa[p][i] = fa[fa[p][i-1]][i-1];
    }
    for(int i=head[p];i;i=edge[i].next){
        if(edge[i].to!=f){
            dfs(edge[i].to,p);
        }
    }
}

int LCA(int p,int q){
    if(deep[p]<deep[q]) swap(p,q);
    for(int i=19;i>=0;i--){
        if(deep[p]-(1<<i)>=deep[q]) p=fa[p][i];
    }
    if(p==q) return p;

    for(int i=19;i>=0;i--){
        if(fa[p][i]!=fa[q][i]){
            p=fa[p][i];q=fa[q][i];
        }
    }
    return fa[p][0];
}



void solve(){
    int n,m,root;cin>>n>>m>>root;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        addedge(u,v);addedge(v,u);
    }

    dfs(root,0);
    while(m--){
        int a,b;cin>>a>>b;
        cout<<LCA(a,b)<<"\n";
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