#include <iostream>
#include <algorithm>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int sx[N];
struct Edge{
    int u,v,w;
}edge[N];
bool cmp(const Edge &a, const Edge &b){
    return a.w>b.w;
}
int Find(int x)
{
    return sx[x]==x?sx[x]:sx[x]=Find(sx[x]);
}

void kruskal(){
    for(int i=0;i<N;i++) sx[i]=i;

    sort(edge+1,edge+1+m,cmp);

    int ans = 0,cnt = 0;

    for(int i=1;i<=m;i++)
    {
        if(cnt == n-1) break;
        int fu=Find(edge[i].u);
        int fv=Find(edge[i].v);
        if(fu!=fv){
            ans+=edge[i].w;
            cnt++;
            sx[fu]=fv;
        }
    }

    if(cnt==n-1) cout<<ans<<"\n";
    else cout<<-1<<"\n";
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
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