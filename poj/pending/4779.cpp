#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define clear(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int ver[M],Next[M],edge[M],head[N];
int dis[N];
bool vis[N];
int tot;
priority_queue<pair<int,int>> que;
void add(int u,int v,int z){
    ver[++tot] = v, edge[tot] = z;
    Next[tot] = head[u],head[u] = tot;
}


void dijkstra(int st,int n,int m){
    clear(vis,0);
    clear(dis,0x3f);
    dis[st] = 0;
    que.push(make_pair(0,st));
    while(!que.empty()){
        int x = que.top().second;que.pop();
        if (vis[x]) continue;

        vis[x] = 1;
        for(int i = head[x];i;i = Next[i]){
            int y = ver[i],z = edge[i];
            if(dis[y] > dis[x] + z){
                dis[y] = dis[x]+z;
                que.push(make_pair(-dis[y],y));
            }
        }
    }
}

void solve(){

    int n,m,s;cin>>n>>m>>s;

    rep(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra(s,n,m);
    rep(i,1,n+1){
        cout<<dis[i]<<" \n"[i==n];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/root/devel/algorithm/in.in","r",stdin); 
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}