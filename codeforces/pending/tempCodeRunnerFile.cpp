#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int M = 2e5 + 5;
int ver[M],head[N],edge[M],Next[M];
int tot;
int d[N],vis[N];
int path[N];
priority_queue<pair<int,int>> q;

void dijkstra(int st){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[st] = 0;
    q.emplace(make_pair(0,st));
    path[st] = 0;
    stack<int> stk;
    while(!q.empty()){
        int x = q.top().second; q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = head[x];i;i = Next[i]){
            int y = ver[i], w = edge[i];
            if(d[y] > d[x] + w){
                d[y]  = d[x] + w;
                path[y] = x;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}

void add(int u,int v,int z){
    ver[++tot]=v,edge[tot]=z;
    Next[tot]=head[u], head[u]=tot;
}

void solve(){
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int u,v,w; cin>> u>> v>>w;
        add(u,v,w);add(v,u,w);
    }
    dijkstra(1);
    path[0] = 1;
    stack<int> st;
    if(d[n]==INF)cout<<-1<<endl;
    else {
        int cnt = 0;
        path[n+1] = n;
        for(int i = path[n+1];i;i = path[i]){
            st.push(i);
        }
        while(!st.empty()){
            if(cnt) cout<<' ';
            cout<<st.top();st.pop();
            cnt++;
        }
        cout<<endl;
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