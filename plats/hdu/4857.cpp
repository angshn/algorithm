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
int n,m;
int head[N],cnt,d[N];
struct Edge{
    int to,next;
}edge[N<<2];


void init(){
    for(int i=0;i<N;i++){
        head[i]=0; d[i]=0;
    }
    cnt=0;
}

void addedge(int u,int v){
    ++cnt;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;d[v]++;

}
#define pii pair<int,int>
struct Cmp{
    bool operator ()(const pii &x,const pii &y){
        if(x.first==y.first) return x.second<y.second;
        return x.first<y.first;
    }
};

void bfs(){

    vector<int> ans;
    priority_queue<int> q; 
    for(int i=1;i<=n;i++){
        if(!d[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.top();q.pop();
        ans.push_back(u);
        for(int i=head[u];i;i=edge[i].next){
            int to=edge[i].to;d[to]--;
            if(!d[to]){
                q.push(to);
            }
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" \n"[i==0];
    }
}


void solve(){
    cin>>n>>m;
    init();
    map<int,bool> hs;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        int t=v*100000+u;
        if(!hs[t]) hs[t]=1;
        else continue;
        addedge(v,u);
    }
    bfs();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}