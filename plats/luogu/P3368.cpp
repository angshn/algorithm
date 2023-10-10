#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
ll tree[N];
int lowbit(int x){return x&(-x);}
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
ll query(int x){
    ll ans = 0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    int old = 0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        update(i,x-old);
        old = x;
    }
    while(m--){
        int op,x,y,k;cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            update(x,k);
            update(y+1,-k);
        }
        else {
            cin>>x;
            cout<<query(x)<<endl;
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
