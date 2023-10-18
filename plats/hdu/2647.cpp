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
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int head[N],d[N],cnt;
struct Edge{
    int to,next;
}edge[N*10];

int rnk[N];
void init(){
    for(int i=0;i<N;i++){
        head[i]=0; d[i]=0; rnk[i]=0;
    }
}
void addedge(int u,int v){
    ++cnt;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;d[v]++;
}
#define pii pair<int,int> 
struct Cmp{
    bool operator ()(const pii &x,const pii &y){
        return x.first<y.first;
    }
};
void bfs(){
    // queue<int> q;
    priority_queue<pii,vector<pii >,greater<pii> > q;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            q.push({0,i});
        }
    }
    int num = 0;
    int maxlvl = -1;
    while(!q.empty()){
        pii u=q.top();q.pop();
        num++;
        rnk[u.second]=u.first;
        maxlvl = max(maxlvl,u.first);
        for(int i=head[u.second];i;i=edge[i].next){
            int to=edge[i].to;
            d[to]--;
            if(d[to]==0){
                q.push({u.first+1,to});
            }
        }
    }
    if(num!=n){//not a topo sequence.
        cout<<"-1\n";
    }
    else {
        int sum=0;
        for(int i=1;i<=n;i++){
            // cout<<i<<" "<<rnk[i]+888<<"\n";
            sum+=rnk[i]+888;
        }
        cout<<sum<<"\n";
    }
}

void solve(){
    while(cin>>n>>m){
        init();
        for(int i=1;i<=m;i++){
            int u,v;cin>>u>>v;
            // if(u==v) continue;
            addedge(v,u);
        }

        bfs();
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