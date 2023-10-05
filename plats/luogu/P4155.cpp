#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 4e5 + 5;
const int INF = 0x3f3f3f3f;

struct Node{
    int id,l,r;
    bool operator < (const Node &x) const {
        return l<x.l;
    }
}w[N<<1];
int n,m;
int n2;
int go[N][20];

void init(){
    int nxt = 1;
    for(int i=1;i<=n2;i++){
        while(nxt <= n2 && w[nxt].l <= w[i].r) nxt++;
        go[i][0] = nxt-1;
    }

    for(int i=1;(1<<i)<=n;++i){
        for(int s=1;s<=n2;s++){
            go[s][i] = go[go[s][i-1]][i-1];
        }
    }
}


int res[N];


void getans(int x){
    int len = w[x].l+m,cur = x,ans = 1;
    for(int i=log2(N);i>=0;i--){
        int pos = go[cur][i];
        if(pos&&w[pos].r<len){
            ans+=1<<i;
            cur = pos;
        }
    }
    res[w[x].id] = ans+1;
}



void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        w[i].id = i;
        cin>>w[i].l>>w[i].r;
        if(w[i].l>w[i].r) w[i].r+=m;
    }

    sort(w+1,w+1+n);
    n2 = n;
    for(int i=1;i<=n;++i){
        n2++;w[n2]=w[i];w[n2].l=w[i].l+m,w[n2].r=w[i].r+m;
    }
    init();

    for(int i=1;i<=n;i++) getans(i);

    for(int i=1;i<=n;i++) cout<<res[i]<<" \n"[i==n];

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}