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
int pa[N];
void init(){
    for(int i=0;i<N;i++) pa[i]=i;
}

int Find(int u){
    return pa[u]==u?pa[u]:pa[u]=Find(pa[u]);
}


struct Edge{
    int u,v,w;
}edge[N];
int n,m;
bool cmp(Edge &a,Edge &b){
    return a.w<b.w;
}

void kruskal(){
    sort(edge+1,edge+1+m,cmp);
    init();
    int ans = 0;int cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(cnt==n-1) break;
        int fu=Find(edge[i].u);
        int fv=Find(edge[i].v);
        if(fu!=fv){
            ans+=edge[i].w;
            pa[fu]=fv;
            cnt++;
        }
    }
    if(cnt==n-1) cout<<ans<<endl;
    else cout<<"orz\n";
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }    
        kruskal();
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