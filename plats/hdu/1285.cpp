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
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int rnk[N];

int head[N],cnt;

struct Edge{
    int to,next,w;
}edge[N<<2];
int d[N];
void addedge(int u,int v,int w=0){
    ++cnt;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;d[v]++;
}
int n,m;
bool hs[N][N];
struct Cmp{
    bool operator()(const pair<int,int> &x,const pair<int,int> &y){
        if(x.first == y.first) return x.second > y.second;
        return x.first>y.first;
    }
};
void bfs(){
    // priority_queue<pair<int,int>,vector<pair<int,int> >,Cmp > q;
    priority_queue<int,vector<int >,greater<int> > q;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            // q.push({0,i});
            q.push(i);
        }
    }
    int cnt=1;
    while(!q.empty()){
        int u = q.top();q.pop();
        rnk[cnt++]=u;
        for(int i=head[u];i;i=edge[i].next){
            d[edge[i].to]--;
            if(!d[edge[i].to]){
                q.push(edge[i].to);
            }
        }
    }
}

void solve(){
    while (cin >> n >> m)
    {
        cnt=0;
        memset(head,0,sizeof(head));
        memset(d,0,sizeof(d));
        memset(hs,0,sizeof(hs));
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            if(hs[u][v]) continue;
            hs[u][v]=1;
            addedge(u,v);
        }
        bfs();
        for (int i = 1; i <= n; i++)
        {
            cout << rnk[i] << " \n"[i == n];
        }
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