#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 2e5 + 5;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int ver[M],edge[M], head[N],Next[M],d[N],col[N];
int tot;
void add(int u,int v,int z){ // add a edge
    ver[++tot] = v,edge[tot] =  1;
    Next[tot] = head[u], head[u] = tot;
}



void solve(){
    tot = 0;
    int n,c0;cin>>n>>c0;
    col[N] = 1;
    memset(col,0,sizeof(col));
    vector<int> c(n-1);
    rep(i,0,n-1) cin>>c[i];
    rep(i,0,n-1){
        int u,v;cin>>u>>v;
        add(u,v,1);
        add(v,u,1);
    }
    rep(i,0,n-1){
        int &v = c[i];
        col[v] = 1;
        
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/root/devel/algorithm/in.in","r",stdin); 
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}