#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int val[N];
struct Node{
    int l,r;
    int sz;
    int val;
}tree[N];

int n;
void build(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin >> tree[i].val;
    }
    for(int i=1;i<=n;i++){
        cin >> tree[i].l;
        cin >> tree[i].r;
    }
}

bool dfs(int u,int v){
    if(u==-1 && v==-1) return true;
    if(u==-1||v==-1) return false;
    if(tree[u].val != tree[v].val) return false;
    return dfs(tree[u].l, tree[v].r) && dfs(tree[u].r, tree[v].l);
}

int cal(int u){
    if(u==-1) return 0;
    int l = cal(tree[u].l);
    int r = cal(tree[u].r);
    
    tree[u].sz = l+r+1;
    return tree[u].sz;
}
void solve(){
    build();
    cal(1);
    int ans = 0;
    for(int i = 1;i<=n;i++) if(dfs(i,i)) ans = max(ans, tree[i].sz);
    cout<<ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}