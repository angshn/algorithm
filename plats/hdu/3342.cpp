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
int n,m;
struct Edge{
    int to,next;
}edge[N];
int head[N],cnt,d[N];
int vis[N];
int loop = false;
int s[N];
void init(){
    for(int i=0;i<N;i++) {
        head[i]=0;
        s[i]=i;
        d[i]=0;
        vis[i]=0;
    }
    cnt=0;
}
int Find(int x){
    return s[x]==x?s[x]:s[x]=Find(s[x]);
}

void add(int u,int v){
    cnt++;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;d[v]++;
}
bool dfs(int x){
    

    vis[x]=1;
    for(int i=head[x];i;i=edge[i].next){
        int to=edge[i].to;
        if(vis[to]){
            return true;
        }
        else if(!vis[to]&&dfs(to)) {
            return true;
        }
    }
    vis[x]=0;
    return false;
    
}

void solve(){
    while(cin>>n>>m,n){
        init();
        for(int i=1;i<=m;i++){
            int u,v;cin>>u>>v;
            add(u,v);
        }
        bool loop = false;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dfs(i)){
                cout<<"NO\n";
                loop = true;
                break;
            }
        }
        if(!loop) cout<<"YES\n";


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